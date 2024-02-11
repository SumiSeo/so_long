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
		printf("length %d\n", len);
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
			if (line[j])
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
