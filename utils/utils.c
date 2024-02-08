/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:08:37 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/07 15:08:39 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	i = 0;
	while (i < env->height)
	{
		free(env->position[i]);
		i++;
	}
	free(env->position);
	free(env->mlx);
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
			if (env->position[i][j] == 'P')
			{
				env->cur_x = j;
				env->cur_y = i;
			}
			j++;
		}
		i++;
	}
	env->count++;
	ft_printf("Calcifer is moving this much : %d\n", env->count);
}
