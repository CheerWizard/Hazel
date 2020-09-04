#pragma once

#include "hzpch.h"
#include "WindowsWindow.h"

namespace Hazel {

	static bool s_GLFWInitialized = false;

	static void glfwError(int error, const char* description) {
		CORE_LOG_ERR("GLFW Error: ({0}): {1}", error, description);
	}

	Window* Window::create(const WindowProps& windowProps) {
		return new WindowsWindow(windowProps);
	}

	WindowsWindow::WindowsWindow(const WindowProps& windowProps) {
		init(windowProps);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& windowProps) {
		m_windowData.title = windowProps._title;
		m_windowData.height = windowProps._height;
		m_windowData.width = windowProps._width;

		CORE_LOG_INFO("Creating window {0} ({1} {2})", windowProps._title, windowProps._width, windowProps._height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			CORE_ASSERT(success, "Count not initialize GLFW!");
			glfwSetErrorCallback(glfwError);
			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)windowProps._width, (int)windowProps._height, m_windowData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_windowData);

		setVSync(true);

		setGLFWCallbacks();
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::setGLFWCallbacks()
	{
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			WindowData& windowData = *(WindowData*) glfwGetWindowUserPointer(window);
			windowData.width = width;
			windowData.width = height;

			WindowResizeEvent event(width, height);
			windowData.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			windowData.eventCallback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}

				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}

			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)x, (float)y);
			windowData.eventCallback(event);
		});
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		m_windowData.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return m_windowData.vSync;
	}

}