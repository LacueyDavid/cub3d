/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_and_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:52:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 01:18:28 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_AND_UTILS_H
# define LIBFT_AND_UTILS_H

# include <aio.h>
# include <stdbool.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color_rgb;

void	ft_bzero(void *s, size_t n);
bool	is_whitespace(char c);
int		get_number(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(const char *s);
int		rgb_to_int(t_color_rgb color_rgb);
char	**ft_realloc(char **file, char *line);
void	free_file(char **file);
int		which_is_bigger(int a, int b);
int		which_is_lower(int a, int b);
void	set_color(t_color_rgb *color, int r, int g, int b);

#endif
