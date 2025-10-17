#pragma once


namespace dx3d
{
	class Logger final
	{
	public:
		enum class LogLevel
		{
			Error = 0,
			Warning,
			Info
		};

		//  Rule of zero which means no need to explicitly declare constructor, destructor, copy and move semantics
		//  if the class doesn't manage resources ( like dynamic memory, file handles, etc. ) directly.
		explicit Logger(LogLevel logLevel = LogLevel::Error);

		// Log a message with the specified log level if it meets the current log level threshold
		void log(LogLevel level, const char* message) const;

		//Add logging methods here in the future

	private:
		LogLevel m_logLevel = LogLevel::Error;
	};
}


