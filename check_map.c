/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:20:31 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 11:27:20 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	can_pass(t_map *game, t_stack *stack, bool *visited)
{
	t_stack	next;

	next.x = game->xi;
	next.y = game->yi;
	if (visited[game->xi + (game->yi * game->width)] == false
		&& check(game))
	{
		game->top++;
		visited[game->xi + (game->yi * game->width)] = true;
		stack[game->top] = next;
	}
}

bool	pass_find(t_map *game, t_stack *stack, bool visited[])
{
	int			i;
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	t_stack		cur;

	while (game->top >= 0)
	{
		i = 0;
		cur = stack[game->top];
		game->top--;
		if (check_end(game, &cur) == true)
			return (true);
		while (i < 4)
		{
			game->xi = cur.x + dx[i];
			game->yi = cur.y + dy[i];
			can_pass(game, stack, visited);
			i++;
		}
	}
	return (false);
}

void	map_count(t_map *game)
{
	int	i;
	int	dep;
	int	col;
	int	play;

	i = 0;
	dep = 0;
	col = 0;
	play = 0;
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'E')
			dep++;
		else if (game->str_line[i] == 'C')
				col++;
		else if (game->str_line[i] == 'P')
				play++;
		else if (game->str_line[i] != '1' && game->str_line[i] != '0')
			ft_exit();
		i++;
	}
	if (!(dep == 1 && play == 1) || col < 1)
		ft_exit();
	game->all_col = col;
	check_map(game);
}

void	check_map(t_map *game)
{
	t_stack	stack[MAX_SIZE];
	t_stack	node;
	bool	visited[MAX_SIZE * MAX_SIZE];

	wall_check(game);
	ft_memset(visited, false, sizeof(visited));
	serch_p(game, &node);
	stack[game->top] = node;
	visited[node.x + (node.y * game->width)] = true;
	if (!pass_find(game, stack, visited))
		ft_exit();
	col_check(game);
}
