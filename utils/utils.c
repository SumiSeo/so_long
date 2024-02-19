/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:08:37 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/19 19:11:46 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_data *env, char c, int j, int i)
{
	if (c == 's')
		mlx_put_image_to_window(env->mlx, env->win, env->spike, j * 50, i * 50);
	else if (c == 'c')
		mlx_put_image_to_window(env->mlx, env->win, env->collect, j * 50, i
			* 50);
	else if (c == 'h')
		mlx_put_image_to_window(env->mlx, env->win, env->hero, j * 50, i * 50);
	else if (c == 'e')
		mlx_put_image_to_window(env->mlx, env->win, env->sortie, j * 50, i
			* 50);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->bg, j * 50, i * 50);
}

char	**free_array(char **array, int count)
{
	while (count >= 0)
	{
		free(array[count]);
		array[count] = NULL;
		count--;
	}
	free(array);
	return (NULL);
}

void	clear_game(t_data *env)
{
	int	i;

	mlx_destroy_image(env->mlx, env->spike);
	mlx_destroy_image(env->mlx, env->collect);
	mlx_destroy_image(env->mlx, env->hero);
	mlx_destroy_image(env->mlx, env->bg);
	mlx_destroy_image(env->mlx, env->sortie);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	i = 0;
	while (i < env->height)
	{
		free(env->position[i]);
		i++;
	}
	free(env->position);
	free(env);
	exit(0);
}

int	mouse_event(t_data *env)
{
	clear_game(env);
	return (0);
}

void	find_cur_position(t_data *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			if (env->position[i][j] == 'P' || env->position[i][j] == '4')
			{
				env->cur_x = j;
				env->cur_y = i;
			}
			j++;
		}
		i++;
	}
	env->count++;
	if (env->count > 1)
		ft_printf("Calcifer is moving this much : %d\n", env->count);
}
