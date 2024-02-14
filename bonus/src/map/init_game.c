/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:30:23 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/14 16:52:40 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_direction2(t_cub3d *cub)
{
	if (cub->player->dir == 'E')
	{
		cub->dirX = 1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = 0.66;
	}
	else if (cub->player->dir == 'W')
	{
		cub->dirX = -1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = -0.66;
	}
}

void	init_direction(t_cub3d *cub)
{
	if (cub->player->dir == 'N')
	{
		cub->dirX = 0;
		cub->dirY = -1;
		cub->planeX = 0.66;
		cub->planeY = 0;
	}
	else if (cub->player->dir == 'S')
	{
		cub->dirX = 0;
		cub->dirY = 1;
		cub->planeX = -0.66;
		cub->planeY = 0;
	}
	init_direction2(cub);
}

void	init_game(t_vars *vars, t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	vars->game_data = malloc(sizeof(t_game));
	if (!vars->game_data)
		ft_err("Creating game data", vars);
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (ft_strchr("NSEW", vars->map[i][j]))
			{
				cub->player->dir = vars->map[i][j];
				vars->map[i][j] = '0';
				cub->player->p_x = j + 0.5;
				cub->player->p_y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->map_str = NULL;
	vars->assets = NULL;
	vars->assets = malloc(sizeof(t_assets));
	if (!vars->assets)
		ft_err("Assets malloc", vars);
	vars->assets->no_link = NULL;
	vars->assets->so_link = NULL;
	vars->assets->we_link = NULL;
	vars->assets->ea_link = NULL;
	vars->assets->f_link = NULL;
	vars->assets->c_link = NULL;
	vars->game_data = NULL;
}
