/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:57:18 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 11:03:01 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	can_pass_c(t_map *game, t_stack *stack, bool *visited)
{
	t_stack	next;

	next.x = game->xi;
	if (visited[game->xi + (game->yi * game->width)] == false
		&& check_c(game, stack))
	{
	next.y = game->yi;
		game->top++;
		visited[game->xi + (game->yi * game->width)] = true;
		stack[game->top] = next;
	}
}

bool	col_find(t_map *game, t_stack *stack, bool visited[])
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
		if (check_p(game, &cur) == true)
			return (true);
		while (i < 4)
		{
			game->xi = cur.x + dx[i];
			game->yi = cur.y + dy[i];
			can_pass_c(game, stack, visited);
			i++;
		}
	}
	return (false);
}

void	col_check(t_map *game)
{
	t_stack	stack[MAX_SIZE];
	t_stack	node;
	bool	visited[MAX_SIZE * MAX_SIZE];

	while (game->all_col > game->col_cnt)
	{
		ft_memset(stack, 0, sizeof(stack));
		ft_memset(visited, false, sizeof(visited));
		serch_c(game, &node);
		stack[game->top] = node;
		visited[node.x + (node.y * game->width)] = true;
		if (!col_find(game, stack, visited))
			ft_exit();
	}
	game->col_cnt = 0;
}
