#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) return 1;

	SDL_Window* window = SDL_CreateWindow("WindowManager", 1280, 720, 0);
	if (!window) return 1;

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) return 1;

	bool isOpen = true;
	while (isOpen) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isOpen = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}