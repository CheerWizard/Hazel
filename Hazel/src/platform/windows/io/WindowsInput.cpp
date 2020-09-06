#include "hzpch.h"

#include "WindowsInput.h"

#include "hazel/app/app.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	WindowsInput::WindowsInput()
	{
		m_window = static_cast<GLFWwindow*>(Application::getInstance().getWindow().getNativeWindow());
	}

	WindowsInput::~WindowsInput()
	{
	}

	bool WindowsInput::isKeyPressed(int keycode)
	{
		auto state = glfwGetKey(m_window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMousePressed(int button)
	{
		auto state = glfwGetMouseButton(m_window, button);
		return state == GLFW_PRESS;
	}

	MousePos WindowsInput::getMousePosition()
	{
		double x, y;
		glfwGetCursorPos(m_window, &x, &y);
		return MousePos(x, y);
	}

}