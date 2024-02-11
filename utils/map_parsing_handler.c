#include "../so_long.h"

void	correct_is(int i, int j, t_data *env)
{
	if (env->position[i - 1][j] != '0' && env->position[i + 1][j] != '0'
		&& env->position[i][j - 1] != '0' && env->position[i][j + 1] != '0')
	{
		ft_printf("ITEM IS SURROUND BY WAR");
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
		ft_printf("EXIT IS SURROUND BY WAR");
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
		ft_printf("HERO IS SURROUND BY WAR");
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