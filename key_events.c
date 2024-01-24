#include "so_long.h"

void	move_up(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y - 1][env->cur_x] == '0')
	{
		env->position[env->cur_y - 1][env->cur_x] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y - 1][env->cur_x] == 'C')
	{
		env->position[env->cur_y - 1][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y - 1][env->cur_x] == 'E')
	{
		env->position[env->cur_y - 1][env->cur_x] = '0';
		exit(0);
	}
	display_game_to_window(env);
}

void	move_right(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y][env->cur_x + 1] == '0')
	{
		env->position[env->cur_y][env->cur_x + 1] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y][env->cur_x + 1] == 'C')
	{
		env->position[env->cur_y][env->cur_x + 1] = '0';
	}
	else if (env->position[env->cur_y][env->cur_x + 1] == 'E')
	{
		env->position[env->cur_y][env->cur_x + 1] = '0';
		exit(0);
	}
	display_game_to_window(env);
}

void	move_left(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y][env->cur_x - 1] == '0')
	{
		env->position[env->cur_y][env->cur_x - 1] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y][env->cur_x - 1] == 'C')
	{
		env->position[env->cur_y][env->cur_x - 1] = '0';
	}
	else if (env->position[env->cur_y][env->cur_x - 1] == 'E')
	{
		env->position[env->cur_y][env->cur_x - 1] = '0';
		exit(0);
	}
	display_game_to_window(env);
}

void	move_down(t_data *env)
{
	find_cur_position(env);
	if (env->position[env->cur_y + 1][env->cur_x] == '0')
	{
		env->position[env->cur_y + 1][env->cur_x] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y + 1][env->cur_x] == 'C')
	{
		env->position[env->cur_y + 1][env->cur_x] = '0';
	}
	else if (env->position[env->cur_y + 1][env->cur_x] == 'E')
	{
		env->position[env->cur_y + 1][env->cur_x] = '0';
		exit(0);
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
		exit(0);
	return (0);
}
