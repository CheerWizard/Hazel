#pragma once 
#include "hzpch.h"
#include "hazel/events/Event.h"

namespace Hazel {
	
	class HAZEL_API Layer {

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

	public:
		inline const std::string& getName() { return m_debugName; }

	public:
		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}
		virtual void onImGuiRender() {}

	protected:
		std::string m_debugName;

	};

}