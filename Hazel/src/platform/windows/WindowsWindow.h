#pragma once

#include <glad/glad.h>

#include "glfw.h"

#include "hazel/window/Window.h"

#include "hazel/events/ApplicationEvent.h"
#include "hazel/events/MouseEvent.h"
#include "hazel/events/KeyEvent.h"

namespace Hazel {

	class WindowsWindow : public Window 
	{

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

	public:
		WindowsWindow(const WindowProps& windowProps);
		virtual ~WindowsWindow();

	public:
		inline unsigned int getHeight() const override {
			return m_windowData.height;
		}

		inline unsigned int getWidth() const override {
			return m_windowData.width;
		}

		inline void* getNativeWindow() const override {
			return m_window;
		}

		inline void setEventCallback(const EventCallbackFn& callback) override {
			m_windowData.eventCallback = callback;
		}

	public:
		void onUpdate() override;
		void setVSync(bool enabled) override;
		bool isVSync() const override;

	private:
		virtual void shutdown();
		virtual void init(const WindowProps& windowProps);
		void initGLFW();
		void initGlad();
		void setGLFWCallbacks();
	};

}