#include <DX3D/Graphics/RenderSystem.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};

	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	auto hr = D3D11CreateDevice(
		NULL,						// Specify Null to use the default adapter (GPU).
		D3D_DRIVER_TYPE_HARDWARE,	// Create a device using the hardware graphics driver.
		NULL,						// Should be 0 or NULL unless the driver is D3D_DRIVER_TYPE_SOFTWARE.
		createDeviceFlags,          // Set debug and Direct2D compatibility flags.
		NULL,						// List of feature levels this app can support.
		0,                          // Number of entries in above list.
		D3D11_SDK_VERSION,			// Always set this to D3D11_SDK_VERSION for Windows Store apps.
		&m_d3dDevice,               // Returns the Direct3D device created.
		&featureLevel,              // Returns feature level of device created.
		&m_d3dDeviceContext         // Returns the device immediate context.
	);

	if (FAILED(hr))
	{
		getLogger().log(Logger::LogLevel::Error, "Failed to create D3D11 device.");
		throw std::runtime_error("Failed to create D3D11 device.");
	}
		
}


dx3d::RenderSystem::~RenderSystem()
{
}
