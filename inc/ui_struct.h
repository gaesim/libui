/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:08:18 by aberrahm          #+#    #+#             */
/*   Updated: 2020/02/22 20:04:20 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_STRUCT
# define UI_STRUCT


// struct pour les fenêtres, penser a ajouter les effets et des thèmes / styles.

typedef struct s_create_win
{
	char	*title;
	int     pos_x;
	int     pos_y;
	int     width;
	int     height;
	Uint32  flags_win;
	Uint32  flags_render;
	Uint32	background_color;
	char	*background_img;
	char	*img_path;

}              t_create_win;

typedef struct      s_ui_window
{
	SDL_Window      *win;
	SDL_Renderer    *render;
	SDL_Texture     *tex;
	SDL_Surface     *surf;
}                   t_ui_window;

#endif