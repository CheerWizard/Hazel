#pragma once

#include "hazel/core.h"
#include "hazel/window/Window.h"
#include "hazel/events/Event.h"
#include "hazel/events/ApplicationEvent.h"
#include "hazel/layer/LayerStack.h"


namespace Hazel {
	
	class HAZEL_API Application {

		public:
			Application();
			virtual ~Application();

			void run();

			void onEvent(Event& event);

			void pushLayer(Layer* layer);
			void pushOverlay(Layer* overlay);

	private:
		bool onWindowClose(WindowCloseEvent& event);
		void updateLayers();
		void updateWindow();
		void updateLayers(Event& e);

		std::unique_ptr<Window> m_window;
		
		bool m_running;
		
		LayerStack m_layerStack;
	};

	// should be implemented on a Hazel's client. 
	Application* onCreate();

}