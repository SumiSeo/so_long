/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:16:32 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/19 19:28:49 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_read(char *filename, t_data *env)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(env);
		exit(0);
	}
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

static void	clean_array(char *line, int fd, t_data *env)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(env);
}

static void	initiate_position2(char *line, t_data *env, int fd, char **array)
{
	int	i;
	int	j;

	i = 0;
	while (line && i < env->height)
	{
		array[i] = (char *)malloc((env->width + 1) * sizeof(char));
		j = 0;
		while (line[j] && line[j] != '\n' && j < env->width)
		{
			array[i][j] = line[j];
			if (env->total_escape != 1 || env->total_hero != 1
				|| env->total_collec == 0)
			{
				error_is("You don't have correct value of hero/escape/collect");
				clean_array(line, fd, env);
				free_array(array, i);
				exit(1);
			}
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	initiate_position(char *filename, t_data *env)
{
	int		fd;
	char	**array;
	char	*line;

	array = (char **)malloc((env->height) * sizeof(char *));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	initiate_position2(line, env, fd, array);
	close(fd);
	env->position = array;
}

int	main(int argc, char **argv)
{
	t_data	*env;
	char	*filename;

	if (argc == 2)
	{
		filename = argv[1];
		env = (t_data *)malloc(sizeof(t_data));
		if (!env)
			free(env);
		map_read(filename, env);
		map_parse(filename, env);
		initiate_position(filename, env);
		find_cur_position(env);
		is_map_valid(env->position, env);
		initiate_characters(env);
		display_game_to_window(env);
		mlx_hook(env->win, X_EVENT_KEY_RELEASE, 1L << 0, &key_press, env);
		mlx_hook(env->win, 17, 0, &mouse_event, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
