/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:02:30 by gsimeon           #+#    #+#             */
/*   Updated: 2019/01/31 07:06:21 by gsimeon          ###   ########.fr       */
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

/*
**		error
*/

int		ui_error(Uint32 error, char *file, int line);
int		ui_exit(Uint32 error);


#endif