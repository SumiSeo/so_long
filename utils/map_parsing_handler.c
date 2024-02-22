/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:26:03 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/22 14:40:33 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_is(char *msg)
{
	ft_printf("***ERROR***\n");
	ft_printf("Because... %s\n", msg);
}

void	initiate_env(t_data *env)
{
	env->count = 0;
	env->total_collec = 0;
	env->total_escape = 0;
	env->total_hero = 0;
	env->collected_collec = 0;
}
