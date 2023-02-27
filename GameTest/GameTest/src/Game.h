#pragma once
#include <iostream>
#include "PlatformerWindow.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	bool InitWindow(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	void Update();
	void Render();
	void HandleEvents();

private:
	const uint32_t m_Width = 960;
	const uint32_t m_Height = 540;

	bool m_Running = false;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	Platformer::PlatformerWindow m_PlatformerWindow;

	const uint32_t m_FPS = 240;

	uint32_t m_frameStart;
	uint32_t m_frameEnd;
};