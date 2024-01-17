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
void	put_image_to_window(t_data *env)
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
				mlx_put_image_to_window(env->mlx, env->win, env->plant1, width
					* 50, height * 50);
			}
			else if (env->total_line[height * env->width + width] == 'P')
			{
				mlx_put_image_to_window(env->mlx, env->win, env->hero, width
					* 50, height * 50);
			}
			else
			{
				mlx_put_image_to_window(env->mlx, env->win, env->tile, width
					* 50, height * 50);
			}
			width++;
		}
		height++;
	}
}
static void	map_init(t_data *env)
{
	int	img_width;
	int	img_height;

	env->mlx = mlx_init();
	if (!env->mlx)
		printf("ERROR with connection");
	env->win = mlx_new_window(env->mlx, 13 * 50, 5 * 50, "so long ~ ");
	if (!env->win)
		printf("ERROR with window");
	env->spike = mlx_xpm_file_to_image(env->mlx, "./images/wallpaper.xpm",
			&img_width, &img_height);
	if (!env->spike)
		printf("ERROR with spike mage");
	env->hole = mlx_xpm_file_to_image(env->mlx, "./images/hole.xpm", &img_width,
			&img_height);
	if (!env->hole)
		printf("ERROR with hole mage");
	env->plant1 = mlx_xpm_file_to_image(env->mlx, "./images/light.xpm",
			&img_width, &img_height);
	if (!env->plant1)
		printf("ERROR with plant1 mage");
	env->plant2 = mlx_xpm_file_to_image(env->mlx, "./images/plant2.xpm",
			&img_width, &img_height);
	if (!env->plant2)
		printf("ERROR with plant2 mage");
	env->plant3 = mlx_xpm_file_to_image(env->mlx, "./images/plant3.xpm",
			&img_width, &img_height);
	if (!env->plant3)
		printf("ERROR with plant3 mage");
	env->hero = mlx_xpm_file_to_image(env->mlx, "./images/calcifer.xpm",
			&img_width, &img_height);
	if (!env->hero)
		printf("ERROR with plant3 mage");
	env->tile = mlx_xpm_file_to_image(env->mlx, "./images/bg.xpm", &img_width,
			&img_height);
	if (!env->hero)
		printf("ERROR with plant3 mage");
	mlx_hook(env->win, X_EVENT_KEY_RELEASE, 1L << 0, &key_press, &env);
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
	printf("TEST %s\n", env->total_line);
	close(fd);
}
void	game_init(char *filename, t_data *env)
{
	int		fd;
	char	*line;
	int		**wall;
	int		length;
	int		i;

	length = env->width * env->height;
	wall = (int **)malloc(sizeof(int *) * length);
	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
		{
			printf("Line 1 %c\n", line[i]);
			i++;
		}
		line = get_next_line(fd);
	}
}
int	main(void)
{
	t_data env;
	char *filename;

	filename = "./maps/t1.solong";
	// env = (t_data *)malloc(sizeof(t_data));
	// if (!env)
	// 	free(env);

	map_read(filename, &env);
	game_init(filename, &env);
	map_init(&env);
	put_image_to_window(&env);
	mlx_loop(env.mlx);
	free(env.total_line);
	return (0);
}