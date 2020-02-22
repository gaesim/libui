/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:39:38 by gsimeon           #+#    #+#             */
/*   Updated: 2020/02/22 20:08:34 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int main()
{
	SDL_DisplayMode		mode;
	// SDL_Window	win;
	int			di;
	ui_init();
	ui_log_category(SDL_LOG_CATEGORY_TEST);


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
	ui_error(1, __FILE__, __func__, __LINE__);
	SDL_Delay(3000);
	return (ui_exit(0));
}