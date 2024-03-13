/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:02:31 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 13:14:31 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map(t_map_enum **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);

}

bool	parsing_map(char *filepath, t_map_data *map_data)
{
	(void)filepath;

	//Map Creation
	map_data->width = 5;
	map_data->height = 5;
	map_data->minimap_wall_color[0] = 255;
	map_data->minimap_wall_color[1] = 255;
	map_data->minimap_wall_color[2] = 255;
	map_data->map = malloc(5 * sizeof(t_map_enum*));
	for (int i = 0; i < 5; i++)
		map_data->map[i] = malloc(sizeof(t_map_enum) * 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 || i == 4 || j == 0 || j == 4)
				map_data->map[i][j] = WALL;
			else if (i == 1 && j == 1)
				map_data->map[i][j] = VOID;
			else if (i == 2 && j == 2)
				map_data->map[i][j] = NORTH;
			else
				map_data->map[i][j] = VOID;
		}
	}

	//Map print
	for (int i = 0; i < 5; i++)
	{
		for(int y = 0; y < 5; y++)
		{
			if (map_data->map[i][y] == WALL)
				printf("x");
			else if (map_data->map[i][y] == VOID)
				printf("o");
			else if (map_data->map[i][y] == NORTH)
				printf("N");
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
