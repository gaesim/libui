/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:39:38 by gsimeon           #+#    #+#             */
/*   Updated: 2020/02/22 20:20:52 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int main()
{
	// SDL_DisplayMode mode;
	t_ui_window 	all;
	t_create_win	window;

	ui_init();
	IMG_Init(IMG_INIT_WEBP);

	window = (t_create_win){.title = "Test", .width = 200, .height = 200, .img_path = "./assets/rick_morty.jpg"};
	all = ui_create_window(&window);
	all.tex = SDL_CreateTextureFromSurface(all.render, all.surf);
	SDL_FreeSurface(all.surf);

	while (1)
	{
		SDL_Event e;
		
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}
		SDL_RenderClear(all.render);
		SDL_RenderCopy(all.render, all.tex, NULL, NULL);
		SDL_RenderPresent(all.render);
	}

	// int val = SDL_GetNumDisplayModes(0);
	// if ((di = SDL_GetWindowDisplayIndex(SDL_CreateWindow("test", 0, 0, 200, 200, 0))) == -1)
	// 	exit(-1);
	// printf("Display Modes %d\nDisplay Index %d\n", val, di);
	// for (size_t i = 0; i < val; i++)
	// {
	// 	SDL_GetDisplayMode(0, i, &mode);
	// 	SDL_Log("Mode %zu\tbpp %i\t%s\t%i x %i", i,
	// 			SDL_BITSPERPIXEL(mode.format), SDL_GetPixelFormatName(mode.format), mode.w, mode.h);
	// }
	// SDL_Delay(3000);
	
	SDL_DestroyRenderer(all.render);
	SDL_DestroyWindow(all.win);

	return (ui_exit(0));
}