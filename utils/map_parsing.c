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

char	*ft_strjoin_without_newline(char *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len && s1[i] != '\n')
		ret[i] = s1[i];
	free(s1);
	while (++j < s2_len && s2[j] != '\n')
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup_without_newline(const char *s1)
{
	int		length;
	int		i;
	char	*casted_str;

	length = 0;
	i = 0;
	if (!s1)
		return (NULL);
	while (s1[length] && s1[length] != '\n')
		length++;
	casted_str = (char *)malloc(sizeof(char) * length + 1);
	if (!casted_str)
		return (NULL);
	while (i < length)
	{
		casted_str[i] = s1[i];
		i++;
	}
	casted_str[i] = '\0';
	return (casted_str);
}

void	check_collect_surrounded(t_data *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->position[i] && i < env->height)
	{
		j = 0;
		while (env->position[i][j] && j < env->width)
		{
			if (env->position[i][j] == 'C')
			{
				if (env->position[i - 1][j] == '1' && env->position[i
					+ 1][j] == '1' && env->position[i][j - 1] == '1'
					&& env->position[i][j + 1] == '1')
				{
					while (i < env->height)
					{
						free(env->position[i]);
						i++;
					}
					ft_printf("YOU CAN NOT COOLECT ITEM WHICH IS SURROUND BY WAR");
					free(env);
					free(env->position);
					exit(1);
				}
			}
			if (env->position[i][j] == 'P')
			{
				if (env->position[i - 1][j] == '1' && env->position[i
					+ 1][j] == '1' && env->position[i][j - 1] == '1'
					&& env->position[i][j + 1] == '1')
				{
					while (i < env->height)
					{
						free(env->position[i]);
						i++;
					}
					ft_printf("YOU CAN NOT MOVE YOUR HERO ITEM WHICH IS SURROUND BY WAR");
					free(env->position);
					free(env);
					exit(1);
				}
			}
			if (env->position[i][j] == '0')
			{
				if (env->position[i + 1][j] == '1' && env->position[i
					- 1][j] == '1' && env->position[i][j + 1] == '1')
				{
					while (i < env->height)
					{
						free(env->position[i]);
						i++;
					}
					ft_printf("YOU CAN NOT MOVE YOUR HERO ITEM WHICH IS SURROUND BY WAR");
					free(env->position);
					free(env);
					exit(1);
				}
			}
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

	i = 0;
	env->count = 0;
	env->total_collec = 0;
	env->total_escape = 0;
	env->total_hero = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < env->height)
	{
		j = 0;
		while (line[j] && line[j] != '\n' && j < env->width)
		{
			if ((i == 0 && line[j] != '1') || (i == env->height - 1
					&& line[j] != '1'))
			{
				while (line)
				{
					free(line);
					line = get_next_line(fd);
				}
				free(env);
				exit(1);
			}
			else if ((j == 0 && line[j] != '1') || (j == env->width - 1
					&& line[j] != '1'))
			{
				while (line)
				{
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
