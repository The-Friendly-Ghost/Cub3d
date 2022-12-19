/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:04:52 by mevan-de          #+#    #+#             */
/*   Updated: 2022/12/19 13:42:20 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

// 1. create an array of t_rays for num_rays
// 2. cast all rays to find the correct distances
// 3. render 3d projected walls, for every ray