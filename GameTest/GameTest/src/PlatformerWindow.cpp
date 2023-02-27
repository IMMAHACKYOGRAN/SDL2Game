#include "PlatformerWindow.h"

namespace Platformer
{

	PlatformerWindow::PlatformerWindow()
	{
		m_DestRect.w = m_Width;
		m_DestRect.h = m_Height;
		m_DestRect.x = m_ScreenPos.x;
		m_DestRect.y = m_ScreenPos.y;
	}

	PlatformerWindow::~PlatformerWindow() {}

	void PlatformerWindow::InitWindow(SDL_Renderer* renderer)
	{
		m_Renderer = renderer;
	}

	void PlatformerWindow::Show()
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(m_Renderer, &m_DestRect);
	}
}