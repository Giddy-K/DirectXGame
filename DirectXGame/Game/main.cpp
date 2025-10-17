#include <DX3D/All.h>


int main()
{
	try
	{
		dx3d::Game game({ dx3d::Logger::LogLevel::Info }); // Set log level to Info for more detailed logging
		game.run();
	}
	catch (const std::runtime_error&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}