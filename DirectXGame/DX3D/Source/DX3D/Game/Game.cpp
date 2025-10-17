#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>

dx3d::Game::Game()
{
	//Last to be created, first to be destroyed
	m_graphicsEngine = std::make_unique<GraphicsEngine>();
	m_display = std::make_unique<Window>();
}

dx3d::Game::~Game()
{
}
