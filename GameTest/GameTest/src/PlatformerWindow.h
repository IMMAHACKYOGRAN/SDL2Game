#pragma once
#include "Vec2.h"
#include "SDL.h"

namespace Platformer
{
	class PlatformerWindow
	{
	public:
		PlatformerWindow();
		~PlatformerWindow();

		void Show();
		void InitWindow(SDL_Renderer* renderer); 

	private:
	
	private:
		const uint32_t m_Width = 480;
		const uint32_t m_Height = 540;

		const Vec2 m_ScreenPos;

		SDL_Rect m_DestRect;
		SDL_Renderer* m_Renderer;
	};
}