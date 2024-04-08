/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_useful_values.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:46:06 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/08 10:36:02 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_USEFUL_VALUES_H
# define CUB3D_USEFUL_VALUES_H

# ifndef WIDTH
// #  define WIDTH 1497
#  define WIDTH 1200
# endif

# ifndef HEIGHT
// #  define HEIGHT 1000
#  define HEIGHT 800
# endif

# ifndef FOV
#  define FOV 60
# endif

# ifndef ROTATE_SPEED
#  define ROTATE_SPEED 0.030
// #  define ROTATE_SPEED 0.075
# endif

// speed etant une fraction de la taille d'un bloc, plus le chiffre est grand, plus la vitesse
// est petite
# ifndef SPEED
// #  define SPEED 25
#  define SPEED 45
# endif

# ifndef SPRINT_SPEED
// #  define SPRINT_SPEED 15
#  define SPRINT_SPEED 25
# endif

#endif
