/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:08:18 by aberrahm          #+#    #+#             */
/*   Updated: 2019/06/05 19:43:13 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_STRUCT
# define UI_STRUCT

typedef struct s_coord
{
    int     x;
    int     y;
    /* data */
}              t_coord;

typedef struct s_sdl
{
    SDL_Window  *win;

}               t_sdl;

//enum des flags de la fenetre (ne sont pas tous presents, notamment ceux concernant l opengl)

typedef enum win_flags win_flags;
enum    win_flags
{
    FL0 = SDL_WINDOW_FULLSCREEN,
    FL1 = SDL_WINDOW_FULLSCREEN_DESKTOP,
    FL2 = SDL_WINDOW_HIDDEN,
    FL3 = SDL_WINDOW_RESIZABLE,
    FL4 = SDL_WINDOW_MINIMIZED,
    FL5 = SDL_WINDOW_MAXIMIZED,
    FP0 = SDL_WINDOWPOS_CENTERED,
    FP1 = SDL_WINDOWPOS_UNDEFINED,
};

#endif