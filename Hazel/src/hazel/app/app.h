#pragma once

#include "hazel/core.h"
#include "hazel/window/Window.h"
#include "hazel/events/Event.h"
#include "hazel/events/ApplicationEvent.h"
#include "hazel/layer/LayerStack.h"


namespace Hazel {

	class HAZEL_API Application {

	private:
		static Application* s_Instance;

	private:
		std::unique_ptr<Window> m_window;
		bool m_running;
		LayerStack m_layerStack;

	public:
		Application();
		virtual ~Application();

	public:
		inline Window& getWindow() { return *m_window; }
		inline static Application& getInstance() { return *s_Instance; }

	public:
		void onEvent(Event& event);
		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		void run() {
			while (m_running) {
				clearBuffer();
				updateLayers();
				updateInputs();
				updateWindow();
			}
		}

	private:
		bool onWindowClose(WindowCloseEvent& event);

		void clearBuffer();
		void updateLayers();
		void updateWindow();
		void updateLayers(Event& e);
		void updateInputs();
	};

	// should be implemented on a Hazel's client. 
	Application* onCreate();

}