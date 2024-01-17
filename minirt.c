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
	int	height;
	int	width;

	height = 0;
	while (height < env->height)
	{
		width = 0;
		while (width < env->width)
		{
			if (env->total_line[height * env->width + width] == '1')
			{
				mlx_put_image_to_window(env->mlx, env->win, env->spike, width
					* 50, height * 50);
			}
			else if (env->total_line[height * env->width + width] == 'C')
			{
				mlx_put_image_to_window(env->mlx, env->win, env->collect, width
					* 50, height * 50);
			}
			else if (env->total_line[height * env->width + width] == 'P')
			{
				mlx_put_image_to_window(env->mlx, env->win, env->hero, width
					* 50, height * 50);
			}
			else
			{
				mlx_put_image_to_window(env->mlx, env->win, env->bg, width * 50,
					height * 50);
			}
			width++;
		}
		height++;
	}
	mlx_hook(env->win, X_EVENT_KEY_RELEASE, 1L << 0, &key_press, &env);
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
	env->total_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		env->height += 1;
		line = get_next_line(fd);
		if (line)
			env->total_line = ft_strjoin_without_newline(env->total_line, line);
		free(line);
	}
	close(fd);
}
// void	game_init(char *filename, t_data *env)
// {
// 	int		fd;
// 	char	*line;
// 	int		**wall;
// 	int		length;
// 	int		i;
// 	length = env->width * env->height;
// 	wall = (int **)malloc(sizeof(int *) * length);
// 	i = 0;
// 	fd = open(filename, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		while (line[i])
// 		{
// 			printf("Line 1 %c\n", line[i]);
// 			i++;
// 		}
// 		line = get_next_line(fd);
// 	}
// }
static char	**initiate_position(char *filename, t_data *env)
{
	int		i;
	int		fd;
	char	**array;
	char	*line;
	int		j;

	i = 0;
	array = (char **)malloc((env->height) * sizeof(char *));
	if (!array)
		return (NULL);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		array[i] = (char *)malloc((env->width) * sizeof(char));
		j = 0;
		while (line[j])
		{
			array[i][j] = line[j];
			printf("simple test %c\n", array[i][j]);
			j++;
		}
		printf("****************\n");
		line = get_next_line(fd);
	}
	close(fd);
	return (array);
}
int	main(void)
{
	t_data *env;
	char *filename;

	filename = "./maps/t1.solong";
	env = (t_data *)malloc(sizeof(t_data));
	if (!env)
		free(env);

	map_read(filename, env);
	// game_init(filename, &env);

	env->position = initiate_position(filename, env);
	initiate_characters(env);
	printf("current position %c\n", env->position[0][0]);
	display_game_to_window(env);
	mlx_loop(env->mlx);
	free(env->total_line);
	return (0);
}