/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:16:18 by sumseo            #+#    #+#             */
/*   Updated: 2024/01/09 17:16:22 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
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
	void	*addr;
	char	*total_line;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*spike;
	void	*collect;
	void	*bg;
	void	*hero;
	char	**position;
	int		cur_x;
	int		cur_y;
}			t_data;

void		send_error_msg(char *s);
int			key_press(int keycode, t_data *env);
char		*ft_strdup_without_newline(const char *s1);
char		*ft_strjoin_without_newline(char *s1, char const *s2);
void		clear_game(t_data *env);
void		put_image_to_window(t_data *env);
void		display_game_to_window(t_data *env);

#endif
