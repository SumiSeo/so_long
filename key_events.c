#include "so_long.h"

void	move_up(t_data *env)
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

void	move_right(t_data *env)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(env->total_line))
	{
		if (env->total_line[i] == 'P')
			break ;
	}
}

void	move_left(t_data *env)
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

void	move_down(t_data *env)
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
	// printf("current position %c\n", env->position[0][0]);
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
