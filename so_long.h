/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:35:29 by sumseo            #+#    #+#             */
/*   Updated: 2024/02/17 16:34:20 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include "stdlib.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 500
# define HEIGHT 500
# define X_EVENT_KEY_PRESS 3
# define X_EVENT_KEY_RELEASE 2
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_DOWN 65364

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*spike;
	void	*collect;
	void	*bg;
	void	*hero;
	void	*sortie;
	char	**position;
	int		count;
	int		cur_x;
	int		cur_y;
	int		total_collec;
	int		total_escape;
	int		total_hero;
	int		collected_collec;
}			t_data;

int			key_press(int keycode, t_data *env);
char		*ft_strdup_without_newline(const char *s1);
char		*ft_strjoin_without_newline(char *s1, char const *s2);
void		clear_game(t_data *env);
void		put_image_to_window(t_data *env);
void		display_game_to_window(t_data *env);
void		find_cur_position(t_data *env);
char		**free_array(char **array, int count);
int			mouse_event(t_data *env);
void		clear_game(t_data *env);
void		find_cur_position(t_data *env);
void		map_parse(char *filename, t_data *env);
void		correct_is(int i, int j, t_data *env);
void		escape_is(int i, int j, t_data *env);
void		person_is(int i, int j, t_data *env);
void		error_is(char *msg);
void		check_valid_map(t_data *env);
void		find_route(char **tab, t_data *env, int x, int y);
void		is_map_valid(char **tab, t_data *env);
void		put_image(t_data *env, char c, int j, int i);
void		initiate_env(t_data *env);
void		control_element(char element, t_data *env, int x, int y);

#endif
