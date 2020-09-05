#include "LayerStack.h"

namespace Hazel {

	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers) {
			delete layer;
		}
	}
	
	void LayerStack::pushLayer(Layer* layer)
	{
		m_layers.emplace(begin() + m_layerIndex, layer);
		m_layerIndex++;
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(begin(), end(), layer);
		if (it != end()) {
			m_layers.erase(it);
			m_layerIndex++;
		}
	}

	void LayerStack::pushOverlay(Layer* overlay)
	{
		m_layers.emplace_back(overlay);
	}

	void LayerStack::popOverlay(Layer* overlay)
	{
		auto it = std::find(begin(), end(), overlay);
		if (it != end()) {
			m_layers.erase(it);
		}
	}

}