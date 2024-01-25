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

static int	mouse_event(t_data *env)
{
	clear_game(env);
	return (0);
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
			else if (env->position[i][j] == 'E')
				mlx_put_image_to_window(env->mlx, env->win, env->sortie, j * 50,
					i * 50);
			else
			{
				mlx_put_image_to_window(env->mlx, env->win, env->bg, j * 50, i
					* 50);
			}
			j++;
		}
		i++;
	}
}

static void	initiate_characters(t_data *env)
{
	int	img_width;
	int	img_height;

	env->mlx = mlx_init();
	if (!env->mlx)
		free(env->mlx);
	env->win = mlx_new_window(env->mlx, env->width * 50, env->height * 50,
			"so long ~ ");
	if (!env->win)
		mlx_destroy_window(env->mlx, env->win);
	env->spike = mlx_xpm_file_to_image(env->mlx, "./textures/cloud.xpm",
			&img_width, &img_height);
	if (!env->spike)
		mlx_destroy_image(env->mlx, env->spike);
	env->collect = mlx_xpm_file_to_image(env->mlx, "./textures/light.xpm",
			&img_width, &img_height);
	if (!env->collect)
		mlx_destroy_image(env->mlx, env->collect);
	env->hero = mlx_xpm_file_to_image(env->mlx, "./textures/calcifer.xpm",
			&img_width, &img_height);
	if (!env->hero)
		mlx_destroy_image(env->mlx, env->hero);
	env->bg = mlx_xpm_file_to_image(env->mlx, "./textures/bg.xpm", &img_width,
			&img_height);
	if (!env->bg)
		mlx_destroy_image(env->mlx, env->bg);
	env->sortie = mlx_xpm_file_to_image(env->mlx, "./textures/sortie.xpm",
			&img_width, &img_height);
	if (!env->sortie)
		mlx_destroy_image(env->mlx, env->sortie);
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

	env->count = 0;
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
		free(line);
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
	env->count++;
	ft_printf("Calcifer is moving this much : %d\n", env->count);
}
int	main(void)
{
	t_data	*env;
	char	*filename;

	filename = "./maps/t2.ber";
	env = (t_data *)malloc(sizeof(t_data));
	if (!env)
		free(env);
	map_read(filename, env);
	initiate_position(filename, env);
	initiate_characters(env);
	display_game_to_window(env);
	mlx_hook(env->win, X_EVENT_KEY_RELEASE, 1L << 0, &key_press, env);
	mlx_hook(env->win, 17, 0, &mouse_event, env);
	mlx_loop(env->mlx);
	return (0);
}
