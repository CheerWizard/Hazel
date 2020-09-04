#include "hazel/layer/Layer.h"
#include "hazel/events/MouseEvent.h"
#include "hazel/events/KeyEvent.h"
#include "hazel/events/ApplicationEvent.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer {

	private:
		float m_time = 0.0f;

	public:
		ImGuiLayer();
		~ImGuiLayer();

	public:
		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& e);

	private:
		// mouse event handler methods.
		bool onMouseButtonPressed(MouseButtonPressedEvent& e);
		bool onMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onMouseScrolled(MouseScrolledEvent& e);
		// key events handler moethds.
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		bool onKeyTyped(KeyTypedEvent& e);
		// window events handler methods.
		bool onWindowResized(WindowResizeEvent& e);

		void displayWindowAndFindDeltaTime();
	};

}