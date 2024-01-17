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
# define KEY_W 119
# define KEY_A 97
# define KEY_S 100
# define KEY_D 115

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
	void	*hole;
	void	*plant1;
	void	*plant2;
	void	*plant3;
	void	*tile;
	void	*hero;
	int		col_cnt;
	int		all_col;
	int		walk_cnt;

}			t_data;

void		send_error_msg(char *s);
int			key_press(int keycode, t_data *env);
char		*ft_strdup_without_newline(const char *s1);
char		*ft_strjoin_without_newline(char *s1, char const *s2);
void		clear_game(t_data *env);
void		put_image_to_window(t_data *env);

#endif
