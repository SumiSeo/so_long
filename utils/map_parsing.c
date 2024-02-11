/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:14:37 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/07 15:14:38 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	find_route(char **tab, t_point size, t_point cur)
void	find_route(char **tab, t_data env)
{
	if (env->cur_y < 0 || env->cur_y >= env->height || env->cur_x < 0
		|| env->cur_x >= env->width)
		return ;
	find_route(tab, (t_data){env->cur_x - 1, env->cur_y});
	// fill(tab, size, (t_point){cur.x + 1, cur.y});
	// fill(tab, size, (t_point){cur.x, cur.y - 1});
	// fill(tab, size, (t_point){cur.x, cur.y + 1});
	printf("TESTSET");
}

void	is_map_valid(char **tab, t_data *env)
{
	find_route(tab, env);
}

void	check_valid_map(t_data *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->height && env->position[i])
	{
		j = 0;
		while (j < env->width && env->position[i][j])
		{
			if (env->position[i][j] == 'P')
			{
				env->cur_x = j;
				env->cur_y = i;
				ft_printf("current psition check x : %d\n", env->cur_x);
				ft_printf("current psition check y : %d\n", env->cur_y);
				is_map_valid(env->position, env);
			}
			if (env->position[i][j] && env->position[i][j] != '1'
				&& env->position[i][j] != '0' && env->position[i][j] != 'E'
				&& env->position[i][j] != 'C' && env->position[i][j] != 'P')
				error_is("The map element is not correct");
			if (env->position[i][j] == 'C')
				correct_is(i, j, env);
			if (env->position[i][j] == 'E')
				escape_is(i, j, env);
			if (env->position[i][j] == 'P')
				person_is(i, j, env);
			j++;
		}
		i++;
	}
}

void	map_parse(char *filename, t_data *env)
{
	int		i;
	int		fd;
	char	*line;
	int		j;
	int		len;

	i = 0;
	env->count = 0;
	env->total_collec = 0;
	env->total_escape = 0;
	env->total_hero = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < env->height)
	{
		len = ft_strlen(line);
		j = 0;
		while (line[j] && line[j] != '\n' && line[j] != '\0' && j < env->width)
		{
			if ((i == 0 && line[j] != '1') || (i == env->height - 1
					&& line[j] != '1') || (j == 0 && line[j] != '1')
				|| (j == env->width - 1 && line[j] != '1'))
			{
				while (line)
				{
					ft_printf("YOU HAVE SOMETHING INSIDE OF THE WAR\n");
					free(line);
					line = get_next_line(fd);
				}
				free(env);
				exit(1);
			}
			if (line[j] == 'C')
				env->total_collec++;
			if (line[j] == 'E')
				env->total_escape++;
			if (line[j] == 'P')
				env->total_hero++;
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
