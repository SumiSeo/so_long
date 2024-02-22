/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:09:33 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/22 14:48:34 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_game_to_window(t_data *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			if (env->position[i][j] == '1')
				put_image(env, 's', j, i);
			else if (env->position[i][j] == '3')
				put_image(env, 'c', j, i);
			else if (env->position[i][j] == '4')
				put_image(env, 'h', j, i);
			else if (env->position[i][j] == '5')
				put_image(env, 'e', j, i);
			else
				put_image(env, 'b', j, i);
			j++;
		}
		i++;
	}
}

void	check_screen_size(t_data *env)
{
	int	map_size_x;
	int	map_size_y;
	int	i;
	int	size_x;
	int	size_y;

	map_size_x = env->width * 50;
	map_size_y = env->height * 50;
	mlx_get_screen_size(env->mlx, &size_x, &size_y);
	if (size_x < map_size_x || size_y < map_size_y)
	{
		ft_printf("Screen is small for display the map.");
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
}

void	initiate_characters(t_data *env)
{
	int	img_width;
	int	img_height;

	env->mlx = mlx_init();
	check_screen_size(env);
	if (!env->mlx)
		free(env->mlx);
	env->win = mlx_new_window(env->mlx, env->width * 50, env->height * 50,
			"so long ~ ");
	env->spike = mlx_xpm_file_to_image(env->mlx, "./textures/cloud.xpm",
			&img_width, &img_height);
	env->collect = mlx_xpm_file_to_image(env->mlx, "./textures/light.xpm",
			&img_width, &img_height);
	env->hero = mlx_xpm_file_to_image(env->mlx, "./textures/calcifer.xpm",
			&img_width, &img_height);
	env->bg = mlx_xpm_file_to_image(env->mlx, "./textures/bg.xpm", &img_width,
			&img_height);
	env->sortie = mlx_xpm_file_to_image(env->mlx, "./textures/sortie.xpm",
			&img_width, &img_height);
}

void	map_parse_loop_free(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
