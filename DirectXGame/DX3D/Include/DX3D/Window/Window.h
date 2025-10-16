#pragma once
#include <DX3D/Core/Base.h>


namespace dx3d
{
	class Window: public Base
	{
	public:
		Window();
		virtual ~Window() override;

	private:
		void* m_handle{}; // Platform-specific window handle (e.g., HWND for Win32)
	};
}


