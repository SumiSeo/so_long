/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:16:32 by sumseo            #+#    #+#             */
/*   Updated: 2024/01/09 17:16:48 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	clear_game(t_data *env)
{
	exit(0);
	env = NULL;
}
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
				mlx_put_image_to_window(env->mlx, env->win, env->spike, j * 50,
					i * 50);
			else if (env->position[i][j] == 'C')
				mlx_put_image_to_window(env->mlx, env->win, env->collect, j
					* 50, i * 50);
			else if (env->position[i][j] == 'P')
				mlx_put_image_to_window(env->mlx, env->win, env->hero, j * 50, i
					* 50);
			else
			{
				mlx_put_image_to_window(env->mlx, env->win, env->bg, j * 50, i
					* 50);
			}
			j++;
		}
		i++;
	}
	mlx_hook(env->win, X_EVENT_KEY_RELEASE, 1L << 0, &key_press, env);
}

static void	initiate_characters(t_data *env)
{
	int	img_width;
	int	img_height;

	env->mlx = mlx_init();
	if (!env->mlx)
		printf("ERROR with connection");
	env->win = mlx_new_window(env->mlx, env->width * 50, env->height * 50,
			"so long ~ ");
	if (!env->win)
		printf("ERROR with window");
	env->spike = mlx_xpm_file_to_image(env->mlx, "./images/wallpaper.xpm",
			&img_width, &img_height);
	if (!env->spike)
		printf("ERROR with spike mage");
	env->collect = mlx_xpm_file_to_image(env->mlx, "./images/light.xpm",
			&img_width, &img_height);
	env->hero = mlx_xpm_file_to_image(env->mlx, "./images/calcifer.xpm",
			&img_width, &img_height);
	if (!env->hero)
		printf("ERROR with plant3 mage");
	env->bg = mlx_xpm_file_to_image(env->mlx, "./images/bg.xpm", &img_width,
			&img_height);
	if (!env->bg)
		printf("ERROR with plant3 mage");
}

static void	map_read(char *filename, t_data *env)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	env->width = ft_strlen(line) - 1;
	env->height = 0;
	free(line);
	while (line)
	{
		env->height += 1;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
}
static void	initiate_position(char *filename, t_data *env)
{
	int		i;
	int		fd;
	char	**array;
	char	*line;
	int		j;

	i = 0;
	array = (char **)malloc((env->height) * sizeof(char *));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < env->height)
	{
		array[i] = (char *)malloc((env->width + 1) * sizeof(char));
		j = 0;
		while (line[j] && line[j] != '\n' && j < env->width)
		{
			array[i][j] = line[j];
			j++;
		}
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	env->position = array;
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
	printf("Currently I am here i : %d, j : %d\n", env->cur_x, env->cur_y);
}
int	main(void)
{
	t_data	*env;
	char	*filename;

	filename = "./maps/t2.solong";
	env = (t_data *)malloc(sizeof(t_data));
	if (!env)
		free(env);
	map_read(filename, env);
	initiate_position(filename, env);
	initiate_characters(env);
	display_game_to_window(env);
	mlx_loop(env->mlx);
	free(env->total_line);
	return (0);
}
