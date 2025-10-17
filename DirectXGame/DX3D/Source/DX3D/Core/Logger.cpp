#include <DX3D/Core/Logger.h>
#include <iostream>

dx3d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "Codewithgiddy | 3D Direct X Engine Game" << std::endl;
	std::clog << "---------------------------------------" << std::endl;
}

void dx3d::Logger::log(LogLevel level, const char* message) const
{
	auto logLevelToString = [](LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Error:   return "ERROR";
		case LogLevel::Warning: return "WARNING";
		case LogLevel::Info:    return "INFO";
		default:                return "UNKNOWN";
		}
	};

	if (level > m_logLevel) return;
	std::clog << "[ DX3D " << logLevelToString(level) << " ]: " << message << std::endl; // Log to standard output (console) and move to next line
}
