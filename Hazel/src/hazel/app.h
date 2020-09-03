#pragma once

#include "core.h"

namespace Hazel {
	
	class HAZEL_API Application {

		public:
			Application();
			virtual ~Application();
			void run();
	
	};

	// should be implemented on a Hazel's client. 
	Application* onCreate();

}