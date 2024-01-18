#include "so_long.h"

void	move_up(t_data *env)
{
	find_cur_position(env);
	printf("up !! lessss go!!\n ");
	if (env->position[env->cur_y - 1][env->cur_x] == '0')
	{
		env->position[env->cur_y - 1][env->cur_x] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
		display_game_to_window(env);
	}
	printf("Currently I am here i : %d, j : %d\n", env->cur_x, env->cur_y);
}

void	move_right(t_data *env)
{
	find_cur_position(env);
	printf("up !! lessss go!!\n ");
	if (env->position[env->cur_y][env->cur_x + 1] == '0')
	{
		env->position[env->cur_y][env->cur_x + 1] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
		display_game_to_window(env);
	}
	printf("Currently I am here i : %d, j : %d\n", env->cur_x, env->cur_y);
}

void	move_left(t_data *env)
{
	find_cur_position(env);
	printf("up !! lessss go!!\n ");
	if (env->position[env->cur_y][env->cur_x - 1] == '0')
	{
		env->position[env->cur_y][env->cur_x - 1] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
		display_game_to_window(env);
	}
	printf("Currently I am here i : %d, j : %d\n", env->cur_x, env->cur_y);
}

void	move_down(t_data *env)
{
	find_cur_position(env);
	printf("up !! lessss go!!\n ");
	if (env->position[env->cur_y + 1][env->cur_x] == '0')
	{
		env->position[env->cur_y + 1][env->cur_x] = 'P';
		env->position[env->cur_y][env->cur_x] = '0';
		display_game_to_window(env);
	}
	printf("Currently I am here i : %d, j : %d\n", env->cur_x, env->cur_y);
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
