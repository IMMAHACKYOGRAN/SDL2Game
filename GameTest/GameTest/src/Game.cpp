#include "Game.h"
#include "Player.h"

Game::Game()
{
	InitWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height);
	m_PlatformerWindow.InitWindow(m_Renderer);
}

Game::~Game()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
}


bool Game::InitWindow(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { std::cout << "Failed at SDL_Init()\nError: " << SDL_GetError() << std::endl; return 0; }

	m_Window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
	if (!m_Window) { std::cout << "Failed at SDL_CreateWindow()\nError: " << SDL_GetError() << std::endl; return 0; }

	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	if (!m_Renderer) { std::cout << "Failed at SDL_CreateRenderer()\nError: " << SDL_GetError() << std::endl; return 0; }

	m_Running = true;
	return 1;
}

void Game::Update()
{

}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);

	m_PlatformerWindow.Show();
	SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);

	SDL_RenderPresent(m_Renderer);
}

void Game::HandleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_QUIT:
		m_Running = false;
		break;
	}
}

void Game::Run()
{
	while (m_Running)
	{	
		m_frameStart = SDL_GetTicks();

		HandleEvents();
		Update();
		Render();

		m_frameEnd = SDL_GetTicks() - m_frameStart;
		if (1000 / m_FPS > m_frameEnd) SDL_Delay(1000 / m_FPS - m_frameEnd);
	}
}