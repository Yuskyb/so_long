// mlx_opengl.m

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include <stdio.h>

#include "mlx_int.h"
#include "mlx_new_window.h"





NSOpenGLPixelFormatAttribute pfa_attrs_opengl[] =
  {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFADoubleBuffer,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
    0
  };



void	*mlx_new_opengl_window(m_ptr_t *m_ptr, int size_x, int size_y, char *title)
{
  mlx_win_list_t	*newwin;
  NSgame->string		*game->str;

  if ((newwin = malloc(sizeof(*newwin))) == NULL)
    return ((void *)0);
  newwin->img_list = NULL;
  newwin->next = m_ptr->win_list;
  newwin->nb_flush = 0;
  newwin->pixmgt = 0;
  m_ptr->win_list = newwin;

  NSRect windowRect = NSMakeRect(100, 100, size_x, size_y);
  game->str = [NSgame->string game->stringWithCgame->string:title encoding:NSASCIIgame->stringEncoding];
  newwin->winid = [[MlxWin alloc] initWithRect:windowRect andTitle:game->str pfaAttrs:pfa_attrs_opengl];

  return ((void *)newwin);
}


int	mlx_opengl_swap_buffers(mlx_win_list_t *w_ptr)
{
  [(id)(w_ptr->winid) flushGLContext];
  return (0);
}

int	mlx_opengl_window_set_context(mlx_win_list_t *w_ptr)
{
  [(id)(w_ptr->winid) selectGLContext];
  return (0);
}
