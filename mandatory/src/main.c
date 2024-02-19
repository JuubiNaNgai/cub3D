/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:03 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/19 09:07:04 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_cub3d	cub;

	vars = NULL;
	if (argc != 2)
		ft_err("Invalid arguments", vars);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		ft_err("Alloc vars", vars);
	init_vars(vars);
	launch_map(vars, argv);
	cub.ptr = mlx_init();
	if (!cub.ptr)
		ft_err("Malloc error", vars);
	mlx_do_sync(cub.ptr);
	cub.window = mlx_new_window(cub.ptr, WIDTH, HEIGHT, "Cub3D");
	if (!cub.window)
		ft_err("Malloc error", vars);
	play_game(cub, vars);
}
