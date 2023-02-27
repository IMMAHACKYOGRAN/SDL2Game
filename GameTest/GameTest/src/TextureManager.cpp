#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* tmp = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);

	return tex;
}
