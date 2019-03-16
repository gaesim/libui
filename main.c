#include "libui.h"

int main()
{
	SDL_DisplayMode		mode;
	// SDL_Window	win;
	int			di;
	ui_init();


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