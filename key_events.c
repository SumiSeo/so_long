/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/07 15:13:44 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y - 1][env->cur_x] == '2')
	{
		env->position[env->cur_y - 1][env->cur_x] = '4';
		env->position[env->cur_y][env->cur_x] = '2';
	}
	else if (env->position[env->cur_y - 1][env->cur_x] == '3')
	{
		env->position[env->cur_y - 1][env->cur_x] = '2';
		env->total_collec--;
	}
	else if (env->position[env->cur_y - 1][env->cur_x] == 'E'
		&& env->total_collec == 1)
	{
		env->position[env->cur_y - 1][env->cur_x] = '2';
		clear_game(env);
	}
	display_game_to_window(env);
}

void	move_right(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y][env->cur_x + 1] == '2')
	{
		env->position[env->cur_y][env->cur_x + 1] = '4';
		env->position[env->cur_y][env->cur_x] = '2';
	}
	else if (env->position[env->cur_y][env->cur_x + 1] == '3')
	{
		env->position[env->cur_y][env->cur_x + 1] = '2';
		env->total_collec--;
	}
	else if (env->position[env->cur_y][env->cur_x + 1] == 'E'
		&& env->total_collec == 1)
	{
		env->position[env->cur_y][env->cur_x + 1] = '2';
		clear_game(env);
	}
	display_game_to_window(env);
}

void	move_left(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y][env->cur_x - 1] == '2')
	{
		env->position[env->cur_y][env->cur_x - 1] = '4';
		env->position[env->cur_y][env->cur_x] = '2';
	}
	else if (env->position[env->cur_y][env->cur_x - 1] == '3')
	{
		env->position[env->cur_y][env->cur_x - 1] = '2';
		env->total_collec--;
	}
	else if (env->position[env->cur_y][env->cur_x - 1] == 'E'
		&& env->total_collec == 1)
	{
		env->position[env->cur_y][env->cur_x - 1] = '2';
		clear_game(env);
	}
	display_game_to_window(env);
}

void	move_down(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y + 1][env->cur_x] == '2')
	{
		env->position[env->cur_y + 1][env->cur_x] = '4';
		env->position[env->cur_y][env->cur_x] = '2';
	}
	else if (env->position[env->cur_y + 1][env->cur_x] == '3')
	{
		env->position[env->cur_y + 1][env->cur_x] = '2';
		env->total_collec--;
	}
	else if (env->position[env->cur_y + 1][env->cur_x] == 'E'
		&& env->total_collec == 1)
	{
		env->position[env->cur_y + 1][env->cur_x] = '2';
		clear_game(env);
	}
	display_game_to_window(env);
}

int	key_press(int keycode, t_data *env)
{
	if (keycode == KEY_UP)
		move_up(env);
	else if (keycode == KEY_RIGHT)
		move_right(env);
	else if (keycode == KEY_LEFT)
		move_left(env);
	else if (keycode == KEY_DOWN)
		move_down(env);
	else if (keycode == KEY_ESC)
		clear_game(env);
	return (0);
}
