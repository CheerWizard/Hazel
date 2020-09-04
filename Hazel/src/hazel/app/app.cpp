#include "hzpch.h"

#include "app.h"

#include <glad/glad.h>


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


namespace Hazel {

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {

	}

	void Application::onEvent(Event& e) {
		EventDispatcher eventDispatcher(e);
		eventDispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		updateLayers(e);
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_layerStack.pushOverlay(overlay);
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	void Application::updateLayers()
	{
		for (Layer* layer : m_layerStack) {
			layer->onUpdate();
		}
	}

	void Application::updateWindow()
	{
		m_window->onUpdate();
	}

	void Application::updateLayers(Event& e)
	{
		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->onEvent(e);
			if (e.isHandled()) 
				break;
		}
	}

	void Application::run()
	{
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			updateLayers();
			updateWindow();
		}
	}

}