#pragma once
#include "SDL_image.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
};