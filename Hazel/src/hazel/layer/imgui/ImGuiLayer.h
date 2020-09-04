#include "hazel/layer/Layer.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& e);

	private:
		float m_time = 0.0f;

	};

}