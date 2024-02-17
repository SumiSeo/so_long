/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:14:37 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/17 17:05:31 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_route(char **tab, t_data *env, int x, int y)
{
	char	element;

	if (y < 0 || y >= env->height || x < 0 || x >= env->width)
		return ;
	element = env->position[y][x];
	if (element == '2' || element == '1' || element == '3' || element == '4')
		return ;
	if (element == '0')
		env->position[y][x] = '2';
	if (element == 'C')
	{
		env->collected_collec++;
		env->position[y][x] = '3';
	}
	if (element == 'P')
		env->position[y][x] = '4';
	if (element == 'E')
	{
		env->position[y][x] = '5';
		env->collected_collec++;
	}
	find_route(tab, env, x - 1, y);
	find_route(tab, env, x + 1, y);
	find_route(tab, env, x, y - 1);
	find_route(tab, env, x, y + 1);
}

void	is_map_valid(char **tab, t_data *env)
{
	int	i;

	i = 0;
	find_route(tab, env, env->cur_x, env->cur_y);
	if (env->collected_collec != env->total_collec)
	{
		while (i < env->height)
		{
			free(env->position[i]);
			i++;
		}
		free(env->position);
		free(env);
		exit(1);
	}
}

void	count_element(char *line, int j, t_data *env)
{
	if (line[j] == 'C')
		env->total_collec++;
	else if (line[j] == 'E')
	{
		env->total_escape++;
		env->total_collec++;
	}
	else if (line[j] == 'P')
		env->total_hero++;
	else if (line[j] != '0' && line[j] != '1')
		error_is("The map element is not correct");
}
void	map_parse_loop(char *line, t_data *env, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (line && i < env->height)
	{
		j = 0;
		while (line[j] && line[j] != '\n' && line[j] != '\0' && j < env->width)
		{
			if ((i == 0 && line[j] != '1') || (i == env->height - 1
					&& line[j] != '1') || (j == 0 && line[j] != '1')
				|| (j == env->width - 1 && line[j] != '1'))
			{
				while (line)
				{
					free(line);
					line = get_next_line(fd);
				}
				free(env);
				exit(1);
			}
			count_element(line, j, env);
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
}
void	map_parse(char *filename, t_data *env)
{
	int		fd;
	char	*line;

	initiate_env(env);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map_parse_loop(line, env, fd);
	close(fd);
}
