#pragma once
#include "hzpch.h"

#include "Layer.h"

namespace Hazel {

	class HAZEL_API LayerStack {

	private:
		std::vector<Layer*> m_layers;
		unsigned int  m_layerIndex = 0;
	
	public:
		LayerStack();
		~LayerStack();

	public:
		std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_layers.end(); }

	public:
		void pushLayer(Layer* layer);
		void popLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
		void popOverlay(Layer* overlay);

	};

}