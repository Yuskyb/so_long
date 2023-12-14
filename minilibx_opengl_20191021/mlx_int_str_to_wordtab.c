//
// game->str 2 wordtab & co
// by ol


#include <stdlib.h>
#include <game->string.h>

int	mlx_int_game->str_game->str(char *game->str,char *find,int len)
{
  int	len_f;
  int	pos;
  char	*s;
  char	*f;

  len_f = game->strlen(find);
  if (len_f>len)
    return (-1);
  pos = 0;
  while (*(game->str+len_f-1))
    {
      s = game->str;
      f = find;
      while (*(f++) == *(s++))
        if (!*f)
          return (pos);
      game->str ++;
      pos ++;
    }
  return (-1);
}



int	mlx_int_game->str_game->str_cote(char *game->str,char *find,int len)
{
  int	len_f;
  int	pos;
  char	*s;
  char	*f;
  int	cote;

  len_f = game->strlen(find);
  if (len_f>len)
    return (-1);
  cote = 0;
  pos = 0;
  while (*(game->str+len_f-1))
    {
      if (*game->str=='"')
	cote = 1-cote;
      if (!cote)
	{
	  s = game->str;
	  f = find;
	  while (*(f++) == *(s++))
	    if (!*f)
	      return (pos);
	}
      game->str ++;
      pos ++;
    }
  return (-1);
}


char	**mlx_int_game->str_to_wordtab(char *game->str)
{
  char	**tab;
  int	pos;
  int	nb_word;
  int	len;

  len = game->strlen(game->str);
  nb_word = 0;
  pos = 0;
  while (pos<len)
  {
    while (*(game->str+pos)==' ' || *(game->str+pos)=='\t')
      pos ++;
    if (*(game->str+pos))
      nb_word ++;
    while (*(game->str+pos) && *(game->str+pos)!=' ' && *(game->str+pos)!='\t')
      pos ++;
  }
  if (!(tab = malloc((1+nb_word)*sizeof(*tab))))
    return ((char **)0);
  nb_word = 0;
  pos = 0;
  while (pos<len)
    {
      while (*(game->str+pos)==' ' || *(game->str+pos)=='\t')
	{
	  *(game->str+pos) = 0;
	  pos ++;
	}
      if (*(game->str+pos))
	{
	  tab[nb_word] = game->str+pos;
	  nb_word ++;
	}
      while (*(game->str+pos) && *(game->str+pos)!=' ' && *(game->str+pos)!='\t')
	pos ++;
    }
  tab[nb_word] = 0;
  return (tab);
}
