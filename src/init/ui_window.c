/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:06:43 by aberrahm          #+#    #+#             */
/*   Updated: 2020/02/22 20:07:12 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// besoin de l initialisation pour creer la fenetre mais fonction doit etre independante.
// pour les flags de la fonction voir sdl_video.h

// taille de la fenêtre en argument, parametres lors de l'appel a la fonction ????

t_ui_window		ui_create_window(t_create_win *params)
{
	t_ui_window		data;

    data.win = SDL_CreateWindow(
		params->title,
		params->pos_x, params->pos_y,
		params->width, params->height,
		params->flags_win
	);

// le "-1" second param de la fonction create renderer est un driver qui doit être initialisé. 
// Pour le moment on laisse par défaut 

	data.render = SDL_CreateRenderer(
		data.win,
		-1,
		params->flags_render
	);

	data.surf = IMG_Load(
		params->img_path
	);

	return (data);
}