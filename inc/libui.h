/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:02:30 by gsimeon           #+#    #+#             */
/*   Updated: 2019/06/05 21:18:09 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBUI_H
# define LIBUI_H

/*
** includes from SDL2
*/

# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include "ui_struct.h"
# include "ui_define.h"

/*
**		init
*/

int		ui_init(void);

/*
**		error
*/
t_sdl   create_window(const char *title, flags xy, t_coord wh, flags win);
int     ui_error(Uint32 error, const char *file, const char *func, const int line);
int		ui_exit(Uint32 error);


#endif
