#pragma once

#include "hazel/window/Window.h"

#include <GLFW/glfw3.h>

#include "hazel/events/ApplicationEvent.h"
#include "hazel/events/MouseEvent.h"
#include "hazel/events/KeyEvent.h"

namespace Hazel {

	class WindowsWindow : public Window 
	{

	public:

		WindowsWindow(const WindowProps& windowProps);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getHeight() const override {
			return m_windowData.height;
		}

		inline unsigned int getWidth() const override {
			return m_windowData.width;
		}

		inline void setEventCallback(const EventCallbackFn& callback) override {
			m_windowData.eventCallback = callback;
		}

		void setVSync(bool enabled) override;
		bool isVSync() const override;

	private:
		virtual void init(const WindowProps& windowProps);
		virtual void shutdown();
		
		void setGLFWCallbacks();

	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_windowData;

	};

}