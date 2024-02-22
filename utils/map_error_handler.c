/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:41:20 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/22 13:21:22 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_correct_item(t_data *env)
{
	if (env->total_escape != 1)
		error_is("You don't have correct value of escape");
	if (env->total_hero != 1)
		error_is("You don't have correct value of hero");
	if (env->total_collec < 2)
		error_is("You don't have correct value of collect");
}