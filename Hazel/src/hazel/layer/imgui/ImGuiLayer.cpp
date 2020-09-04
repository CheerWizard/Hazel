#include "hzpch.h"

#include "ImGuiLayer.h"


#include "imgui.h"
#include <glad/glad.h>

#include "hazel/io/KeyboardCodes.h"
#include "hazel/app/app.h"
#include "hazel/time/TimeUtil.h"

#include "platform/opengl/ImGuiOpenGLRenderer.h"

namespace Hazel {

	ImGuiLayer::ImGuiLayer() : Layer("ImGui")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::onAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
		io.KeyMap[ImGuiKey_Tab] = HZ_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = HZ_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = HZ_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = HZ_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = HZ_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = HZ_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = HZ_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = HZ_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = HZ_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = HZ_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = HZ_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = HZ_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = HZ_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = HZ_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = HZ_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = HZ_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = HZ_KEY_A;
		io.KeyMap[ImGuiKey_C] = HZ_KEY_C;
		io.KeyMap[ImGuiKey_V] = HZ_KEY_V;
		io.KeyMap[ImGuiKey_X] = HZ_KEY_X;
		io.KeyMap[ImGuiKey_Y] = HZ_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = HZ_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDetach()
	{

	}

	void ImGuiLayer::onUpdate()
	{
		displayWindowAndFindDeltaTime();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::CloseCurrentPopup

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::displayWindowAndFindDeltaTime() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::getInstance();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());
		// TODO: consider to add delta time in ImGuiIO.
	}

	void ImGuiLayer::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseButtonPressed));
		dispatcher.dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseButtonReleased));
		dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseScrolled));
		dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseMoved));
		dispatcher.dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyPressed));
		dispatcher.dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyReleased));
		dispatcher.dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyTyped));
		dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(ImGuiLayer::onWindowResized));
	}

	bool ImGuiLayer::onMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getButton()] = true;

		return false;
	}

	bool ImGuiLayer::onMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getButton()] = false;

		return false;
	}

	bool ImGuiLayer::onMouseMoved(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.getX(), e.getY());

		return false;
	}

	bool ImGuiLayer::onMouseScrolled(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.getXOffset();
		io.MouseWheelH += e.getYOffset();

		return false;
	}

	bool ImGuiLayer::onKeyPressed(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[HZ_KEY_LEFT_CONTROL] || io.KeysDown[HZ_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[HZ_KEY_LEFT_SHIFT] || io.KeysDown[HZ_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[HZ_KEY_LEFT_ALT] || io.KeysDown[HZ_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[HZ_KEY_LEFT_SUPER] || io.KeysDown[HZ_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::onKeyReleased(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = false;

		return false;
	}

	bool ImGuiLayer::onKeyTyped(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.getKeyCode();
		if (keycode > 0 && keycode < 0x10000) {
			io.AddInputCharacter((unsigned short) keycode);
		}

		return false;
	}

	bool ImGuiLayer::onWindowResized(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.getWidth(), e.getHeight());

		return false;
	}

}