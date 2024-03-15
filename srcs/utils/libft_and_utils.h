/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_and_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:52:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 15:46:34 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_AND_UTILS_H
# define LIBFT_AND_UTILS_H

# include "cub3d_includes.h"
# include "image_data.h"
# include "player.h"

void	ft_bzero(void *s, size_t n);
bool	is_whitespace(char c);
int		get_number(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(const char *s);
int		rgb_to_int(int color_rgb[3]);
char	**ft_realloc(char **file, char *line);
void	free_file(char **file);
void	rasterization(t_line line, t_img_data *img, int color);

#endif
