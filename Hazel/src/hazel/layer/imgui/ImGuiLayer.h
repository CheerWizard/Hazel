#pragma once

#include "hazel/layer/Layer.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer {

	private:
		float m_time = 0.0f;

	public:
		ImGuiLayer();
		~ImGuiLayer();

	public:
		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;
		
		void begin();
		void end();
	};

}