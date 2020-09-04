#include "LayerStack.h"

namespace Hazel {

	LayerStack::LayerStack()
	{
		m_layerIterator = begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers) {
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		m_layerIterator = m_layers.emplace(m_layerIterator, layer);
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(begin(), end(), layer);
		if (it != end()) {
			m_layers.erase(it);
			m_layerIterator--;
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