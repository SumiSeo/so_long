#include "so_long.h"

void	move_w(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		printf("How much %zu\n", ft_strlen(env->total_line));
		if (env->total_line[i] == 'P')
		{
			printf("I am here");
			break ;
		}
		else
		{
			printf("I am not here");
		}
	}
	printf("Where am I ?");
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
