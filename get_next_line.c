/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:20:07 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 15:20:33 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}

char	*obtain_remaining(char *bassin_buffer)
{
	char	*temp;
	char	*newline;

	newline = ft_strchr(bassin_buffer, '\n');
	if (newline)
	{
		temp = ft_strdup(newline + 1);
		free(bassin_buffer);
		return (temp);
	}
	free(bassin_buffer);
	return (NULL);
}

char	*extract_line(char *bassin_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	while (bassin_buffer[i] && bassin_buffer[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (bassin_buffer[i] && bassin_buffer[i] != '\n')
	{
		temp[i] = bassin_buffer[i];
		i++;
	}
	if (bassin_buffer[i] && bassin_buffer[i] == '\n')
		temp[i] = bassin_buffer[i];
	temp[++i] = '\0';
	return (temp);
}

char	*read_line(char *bassin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		bassin_buffer = ft_strjoin(bassin_buffer, cup_buffer);
		if (ft_strchr(bassin_buffer, '\n'))
			break ;
	}
	free(cup_buffer);
	return (bassin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*bassin_buffer;
	char		*line;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bassin_buffer)
		bassin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(bassin_buffer, '\n'))
		bassin_buffer = read_line(bassin_buffer, fd);
	if (!bassin_buffer)
		return (NULL);
	line = extract_line(bassin_buffer);
	if (line && line[0] == '\0')
	{
		free(line);
		free(bassin_buffer);
		bassin_buffer = NULL;
		return (NULL);
	}
	bassin_buffer = obtain_remaining(bassin_buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	fd = open("poem3.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (s)
// 	{
// 		printf("Final [%s]\n", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}
// 	free(s);
// 	close(fd);
// }
