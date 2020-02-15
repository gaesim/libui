/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:39:38 by gsimeon           #+#    #+#             */
/*   Updated: 2020/02/15 20:05:18 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int main()
{
	SDL_DisplayMode mode;
	t_sdl *createwin;
	SDL_Texture *tex;
	SDL_Surface *surf;
	int di;
	t_coord xy;
	t_coord wh;
	ui_init();
	IMG_Init(IMG_INIT_WEBP);

	tex = NULL;
	surf = NULL;
	// create_window(xy, wh);
	createwin->win = SDL_CreateWindow("Ma fenetre test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_FULLSCREEN);
	createwin->render = SDL_CreateRenderer(createwin->win, -1, SDL_RENDERER_ACCELERATED);

	surf = IMG_Load("../assets/rick_morty.jpg");
	tex = SDL_CreateTextureFromSurface(createwin->render, surf);
	SDL_FreeSurface(surf);

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
	}

	SDL_RenderClear(createwin->render);
	SDL_RenderCopy(createwin->render, tex, NULL, NULL);
	SDL_RenderPresent(createwin->render);

	int val = SDL_GetNumDisplayModes(0);
	if ((di = SDL_GetWindowDisplayIndex(SDL_CreateWindow("test", 0, 0, 200, 200, 0))) == -1)
		exit(-1);
	printf("Display Modes %d\nDisplay Index %d\n", val, di);
	for (size_t i = 0; i < val; i++)
	{
		SDL_GetDisplayMode(0, i, &mode);
		SDL_Log("Mode %zu\tbpp %i\t%s\t%i x %i", i,
				SDL_BITSPERPIXEL(mode.format), SDL_GetPixelFormatName(mode.format), mode.w, mode.h);
	}
	SDL_Delay(3000);
	SDL_DestroyRenderer(createwin->render);
	SDL_DestroyWindow(createwin->win);

	return (ui_exit(0));
}