/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:39:38 by gsimeon           #+#    #+#             */
/*   Updated: 2019/06/26 01:32:43 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int main()
{
	SDL_DisplayMode		mode;
	// SDL_Window	win;
	int			di;
	t_coord xy;
	t_coord wh;
	ui_init();
	// create_window(xy, wh);

	int val = SDL_GetNumDisplayModes(0);
	if ((di = SDL_GetWindowDisplayIndex(SDL_CreateWindow("test", 0, 0 ,200 ,200, 0))) == -1)
		exit(-1);
	printf("Display Modes %d\nDisplay Index %d\n", val, di);
	for(size_t i = 0; i < val; i++)
	{
		SDL_GetDisplayMode(0, i, &mode);
		SDL_Log("Mode %zu\tbpp %i\t%s\t%i x %i", i,
        SDL_BITSPERPIXEL(mode.format), SDL_GetPixelFormatName(mode.format), mode.w, mode.h);
	}
	SDL_Delay(3000);
	return (ui_exit(0));
}