#pragma once
#include "hazel/io/Input.h"
#include "platform/windows/glfw.h"

namespace Hazel {

	class WindowsInput : public Input {

	private:
		GLFWwindow* m_window;

	public:
		WindowsInput();
		~WindowsInput();

	protected:
		virtual bool isKeyPressed(int keycode) override;
		virtual bool isMousePressed(int button) override;
		virtual MousePos getMousePosition() override;
	};

}