/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:02:30 by gsimeon           #+#    #+#             */
/*   Updated: 2020/02/22 21:16:28 by gsimeon          ###   ########.fr       */
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

/*
**		init
*/

int		ui_init(void);
int     ui_log_category(int new_category);

/*
**		error
*/

int     ui_error(Uint32 error, const char *file, const char *func, const int line);
int		ui_exit(Uint32 error);


#endif
