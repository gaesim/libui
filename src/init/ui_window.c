/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:06:43 by aberrahm          #+#    #+#             */
/*   Updated: 2020/02/15 19:00:38 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// besoin de l initialisation pour creer la fenetre mais fonction doit etre independante.
// pour les flags de la fonction voir sdl_video.h

void    ui_create_window()
{}

// int   create_window(t_coord xy, t_coord wh)
// {
//     t_sdl  *all;

//     all = NULL;
//     xy.x = SDL_WINDOWPOS_UNDEFINED;
//     xy.y = SDL_WINDOWPOS_UNDEFINED;
//     wh.w = 800;
//     wh.h = 400;
//     if (ui_init() != 0)
//         return (ui_error(1, __FILE__, __func__, __LINE__));
//     else
//     all->win = SDL_CreateWindow("Ma fenetre", xy.x, xy.y, wh.w, wh.h, FL0);

//     return(0);
// }

// int ui_create_window(int w, int h, )
// {

// }