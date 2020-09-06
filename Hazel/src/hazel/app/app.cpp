#include "hzpch.h"

#include "app.h"

#include <glad/glad.h>

#include "hazel/io/Inputs.h"

namespace Hazel {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		setupWindow();
		setupImGuiLayer();
	}

	Application::~Application() {

	}

	void Application::setupWindow() {
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	void Application::setupImGuiLayer() {
		m_imguiLayer = new ImGuiLayer();
		pushOverlay(m_imguiLayer);
	}

	void Application::onEvent(Event& e) {
		EventDispatcher eventDispatcher(e);
		eventDispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

		updateLayerEvents(e);
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_layerStack.pushOverlay(overlay);
		overlay->onAttach();
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	void Application::clearBuffer()
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Application::updateLayers()
	{
		for (Layer* layer : m_layerStack) {
			layer->onUpdate();
		}
	}

	void Application::updateImGuiLayer() {
		m_imguiLayer->begin();
		for (Layer* layer : m_layerStack) {
			layer->onImGuiRender();
		}
		m_imguiLayer->end();
	}

	void Application::updateWindow()
	{
		m_window->onUpdate();
	}

	void Application::updateLayerEvents(Event& e)
	{
		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->onEvent(e);
			if (e.isHandled()) 
				break;
		}
	}

	void Application::updateInputs()
	{
		Input* input = Inputs::getInput();
		// update all inputs...
		MousePos mousePos = input->getMousePosition();
		CORE_LOG_TRACE("{0}, {1}", mousePos.x, mousePos.y);
	}

}