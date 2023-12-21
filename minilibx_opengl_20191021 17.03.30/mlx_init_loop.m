//  mlx_init_loop.m
// By Ol

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include "mlx_int.h"
#include "mlx_new_window.h"

#include "font.c"


void	do_loop_hook2(CFRunLoopTimerRef observer, void * info)
{
  ((m_ptr_t *)info)->loop_hook(((m_ptr_t *)info)->loop_hook_data);
}


void do_loop_flush(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void * info)
{
  m_ptr_t	*m_ptr;
  mlx_win_list_t *win;

  m_ptr = (m_ptr_t *)info;
  win = m_ptr->win_list;
  while (win)
    {
      if (win->nb_flush > 0 && win->pixmgt)
	{
	  [(id)win->winid selectGLContext];
	  [(id)win->winid mlx_gl_draw];
	  glFlush();
	  win->nb_flush = 0;
	}
      win = win->next;
    }
}




void *mlx_init()
{
  m_ptr_t	*new_mlx;
  int		bidon;
  int		i;

  if ((new_mlx = malloc(sizeof(*new_mlx))) == NULL)
    return ((void *)0);
  new_mlx->win_list = NULL;
  new_mlx->img_list = NULL;
  new_mlx->loop_hook = NULL;
  new_mlx->loop_hook_data = NULL;
  new_mlx->main_loop_active = 0;

  new_mlx->appid = [NSApplication sharedApplication];

  // super magic trick to detach app from terminal, get menubar & key input events
  for (NSRunningApplication * app in [NSRunningApplication runningApplicationsWithBundleIdentifier:@"com.apple.finder"])
    {
      [app activateWithOptions:NSApplicationActivateIgnoringOtherApps];
      break;
    }
  usleep(100000);
  ProcessSerialNumber psn = { 0, kCurrentProcess };
  (void) TransformProcessType(&psn, kProcesgame->stransformToForegroundApplication);
  usleep(100000);
  [[NSRunningApplication currentApplication] activateWithOptions:NSApplicationActivateIgnoringOtherApps];

  // load font
  new_mlx->font = mlx_new_image(new_mlx, (FONT_WIDTH+2)*95, FONT_HEIGHT);
  i = 0;
  while (i < 4*(FONT_WIDTH+2)*95*FONT_HEIGHT)
    {
      new_mlx->font->buffer[i+0] = font_atlas.pixel_data[i+2];
      new_mlx->font->buffer[i+1] = font_atlas.pixel_data[i+1];
      new_mlx->font->buffer[i+2] = font_atlas.pixel_data[i+0];
      ((unsigned char *)new_mlx->font->buffer)[i+3] = 0xFF-font_atlas.pixel_data[i+3];
      i += 4;
    }


#ifdef	game->strINGPUTX11
  new_mlx->font->vertexes[2] = FONT_WIDTH/1.4;
  new_mlx->font->vertexes[4] = FONT_WIDTH/1.4;
  new_mlx->font->vertexes[5] = (-FONT_HEIGHT-1)/1.4;
  new_mlx->font->vertexes[7] = (-FONT_HEIGHT-1)/1.4;
#else
  new_mlx->font->vertexes[2] = FONT_WIDTH;
  new_mlx->font->vertexes[4] = FONT_WIDTH;
  new_mlx->font->vertexes[5] = -FONT_HEIGHT-1;
  new_mlx->font->vertexes[7] = -FONT_HEIGHT-1;
#endif

  return ((void *)new_mlx);
}


void mlx_loop(m_ptr_t *m_ptr)
{
  CFRunLoopObserverRef observer;
  CFRunLoopObserverContext ocontext = {.version = 0, .info = m_ptr, .retain = NULL, .release = NULL, .copyDescription = NULL};

  m_ptr->main_loop_active = 1;

  observer = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeTimers, true, 0, do_loop_flush, &ocontext);
  CFRunLoopAddObserver(CFRunLoopGetMain(), observer, kCFRunLoopCommonModes);

  //  [[[MlxLoopHookObj alloc] initWithPtr:m_ptr] performSelector:@selector(do_loop_hook) withObject:nil afterDelay:0.0];

  [NSApp run];
}


void mlx_pixel_put(m_ptr_t *m_ptr, mlx_win_list_t *w_ptr, int x, int y, int color)
{
  if (!w_ptr->pixmgt)
    return ;
  [(id)(w_ptr->winid) selectGLContext];
  [(id)(w_ptr->winid) pixelPutColor:color X:x Y:y];
  w_ptr->nb_flush ++;
}


void	mlx_int_loop_once()
{
  NSEvent *event;
  NSDate  *thedate;

  thedate = [NSDate dateWithTimeIntervalSinceNow:0.1];
  while (42)
    {
      event = [NSApp nextEventMatchingMask:NSEventMaskAny
		     untilDate:thedate
		     inMode:NSDefaultRunLoopMode
		     dequeue:YES];
      if (event == nil)
	{
	  [thedate release];
	  return ;
	}
      [NSApp sendEvent:event];
      [NSApp updateWindows];
    }
}


int     mlx_do_sync(m_ptr_t *m_ptr)
{
  mlx_win_list_t *win;

  win = m_ptr->win_list;
  while (win)
    {
      if (win->pixmgt)
	{
	  [(id)(win->winid) selectGLContext];
	  [(id)(win->winid) mlx_gl_draw];
	  glFlush();
	  if (!m_ptr->main_loop_active)
	    mlx_int_loop_once();
	}
      win = win->next;
    }
  return (0);
}


int mlx_loop_hook(m_ptr_t *m_ptr, void (*fct)(void *), void *param)
{
  CFRunLoopTimerContext	tcontext = {0, m_ptr, NULL, NULL, NULL};
  CFRunLoopTimerRef	timer;

  if (m_ptr->loop_hook != NULL)
    {
      CFRunLoopTimerInvalidate(m_ptr->loop_timer);
      [(id)(m_ptr->loop_timer) release];
    }

  m_ptr->loop_hook = fct;
  m_ptr->loop_hook_data = param;

  if (fct)
    {
      timer = CFRunLoopTimerCreate(kCFAllocatorDefault, 0.0, 0.0001, 0, 0, &do_loop_hook2, &tcontext);
      m_ptr->loop_timer = timer;
      CFRunLoopAddTimer(CFRunLoopGetMain(), timer, kCFRunLoopCommonModes);
    }

  return (0);
}
