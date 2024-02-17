/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:26:03 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/17 15:10:03 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	correct_is(int i, int j, t_data *env)
{
	if (env->position[i - 1][j] != '0' && env->position[i + 1][j] != '0'
		&& env->position[i][j - 1] != '0' && env->position[i][j + 1] != '0')
	{
		ft_printf("ITEM IS SURROUNDED BY WALL");
		free_array(env->position, env->height - 1);
		free(env);
		exit(1);
	}
}

void	escape_is(int i, int j, t_data *env)
{
	if (env->position[i - 1][j] != '0' && env->position[i + 1][j] != '0'
		&& env->position[i][j - 1] != '0' && env->position[i][j + 1] != '0')
	{
		ft_printf("EXIT IS SURROUNDED BY WALL");
		free_array(env->position, env->height - 1);
		free(env);
		exit(1);
	}
}

void	person_is(int i, int j, t_data *env)
{
	if (env->position[i - 1][j] != '0' && env->position[i + 1][j] != '0'
		&& env->position[i][j - 1] != '0' && env->position[i][j + 1] != '0')
	{
		ft_printf("HERO IS SURROUNDED BY WALL");
		free_array(env->position, env->height - 1);
		free(env);
		exit(1);
	}
}

void	error_is(char *msg)
{
	ft_printf(msg);
	exit(1);
}

void	initiate_env(t_data *env)
{
	env->count = 0;
	env->total_collec = 0;
	env->total_escape = 0;
	env->total_hero = 0;
	env->collected_collec = 0;
}
