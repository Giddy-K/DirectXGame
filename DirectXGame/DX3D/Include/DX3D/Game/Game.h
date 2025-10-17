#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>

namespace dx3d
{
	class Game : public Base
	{
	public:
		Game();
		virtual ~Game() override;

		virtual void run() final;

	private:
		//Last to be created, first to be destroyed
		std::unique_ptr<GraphicsEngine> m_graphicsEngine{};
		std::unique_ptr<Window> m_display{};
		bool m_isRunning{ true };
	};
}


