#include "app.h"
#include <thread>
#include <chrono>
#include <iostream>
#include "logger/Log.h"
#include "events/ApplicationEvent.h"
#include "logger/Log.h"

#define CURRENT_TIME std::chrono::high_resolution_clock::now()

using namespace std::chrono_literals;

namespace Hazel {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run()
	{
		
		WindowResizeEvent e(1280, 720);
		CORE_LOG_TRACE(e);

		while (true) {
			// emulate work
		}
	}

}