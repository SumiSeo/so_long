#include "so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

void	move_w(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		if (env->total_line[i] == 'P')
			break ;
	}
	if (env->total_line[i - env->width] == 'C')
		env->col_cnt++;
	if (env->total_line[i - env->width] == 'E' && env->all_col == env->col_cnt)
		clear_game(env);
	else if (env->total_line[i - env->width] != '1' && env->total_line[i
		- env->width] != 'E')
	{
		env->total_line[i] = '0';
		env->total_line[i - env->width] = 'P';
		env->walk_cnt++;
		put_image_to_window(env);
	}
	// if (env->total_line[i - env->width] == 'C')
	// 	env->collect++;
}

void	move_s(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		if (env->total_line[i] == 'P')
			break ;
	}
	// if (env->total_line[i - env->width] == 'C')
	// 	env->collect++;
}

void	move_a(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		if (env->total_line[i] == 'P')
			break ;
	}
	// if (env->total_line[i - env->width] == 'C')
	// 	env->collect++;
}

void	move_d(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		if (env->total_line[i] == 'P')
			break ;
	}
	// if (env->total_line[i - env->width] == 'C')
	// 	env->collect++;
}

int	key_press(int keycode, t_data *env)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_W)
		move_w(env);
	else if (keycode == KEY_S)
		move_s(env);
	else if (keycode == KEY_A)
		move_a(env);
	else if (keycode == KEY_D)
		move_d(env);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
