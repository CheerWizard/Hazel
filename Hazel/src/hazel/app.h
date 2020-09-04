#pragma once

#include "core.h"
#include "hazel/Window.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"


namespace Hazel {
	
	class HAZEL_API Application {

		public:
			Application();
			virtual ~Application();

			void run();

			void onEvent(Event& event);

	private:
		bool onWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_window;
		bool m_running;
	};

	// should be implemented on a Hazel's client. 
	Application* onCreate();

}