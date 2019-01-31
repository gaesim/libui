#include "libui.h"

int main()
{
	ui_init();



	int val = SDL_GetNumDisplayModes(0);
	printf("Display Modes %d\n", val);

	SDL_Delay(3000);
	return (0);
}