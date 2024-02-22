/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:41:20 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/22 17:53:00 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_correct_item(t_data *env)
{
	if (env->total_escape != 1)
		error_is("You don't have correct value of escape.");
	else if (env->total_hero != 1)
		error_is("You don't have correct value of hero.");
	else if (env->total_collec < 2 || env->total_escape != 1)
		error_is("You don't have correct value of collect.");
}

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

static void	file_format_wrong(void)
{
	error_is("File name is not correct");
	exit(0);
}

int	is_fileformat_correct(char *file)
{
	char	ber;
	char	*test;
	int		i;
	char	*realber;

	realber = "ber";
	ber = 'b';
	test = my_strchr(file, ber);
	i = 0;
	if (test)
	{
		while (test[i])
		{
			if (test[i] == realber[i])
				i++;
			else
				file_format_wrong();
		}
	}
	else
		file_format_wrong();
	return (1);
}
