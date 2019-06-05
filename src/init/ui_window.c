/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:06:43 by aberrahm          #+#    #+#             */
/*   Updated: 2019/06/05 21:17:51 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// besoin de l initialisation pour creer la fenetre mais fonction doit etre independante.
// pour les flags de la fonction voir sdl_video.h

t_sdl   create_window(const char *title, flags xy, t_coord wh, flags win)
{
    t_sdl   *win;
    
    win = SDL_Create_Window(&title, )


    return (&win);
}