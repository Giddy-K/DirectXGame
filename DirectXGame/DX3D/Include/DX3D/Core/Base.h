#pragma once
#include <DX3D/Core/Common.h>

namespace dx3d
{
	class Base
	{
		public:
			explicit Base(const BaseDesc& desc); //Only takes one parameter
			virtual ~Base();
			virtual Logger& getLogger() const noexcept final; //does not modify the internal state of the class, noexcept guarantees it won't throw exceptions, final prevents further overrides in derived classes


	protected:
		Base(const Base&) = delete;
		Base& operator=(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator=(Base&&) = delete;

	protected:
		// Reference to the global logger instance depenency injection pattern
		// This assumes that a global logger instance exists and is accessible
		// throughout the application lifecycle.
		Logger& m_logger;

	};
}