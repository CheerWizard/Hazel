#include "Hazel.h"

class ExampleLayer : public Hazel::Layer {
	
public:
	
	ExampleLayer() : Layer("Example") 
	{}

	void onUpdate() override {
		CLIENT_LOG_INFO("ExampleLayer: onUpdate()");
	}

	void onEvent(Hazel::Event& event) override {
		CLIENT_LOG_TRACE("ExampleLayer : {0}", event);
	}

};

class Sandbox : public Hazel::Application {

	public:

		Sandbox() {
			pushLayer(new ExampleLayer());
			pushOverlay(new Hazel::ImGuiLayer());
		}

		~Sandbox() {

		}

};

Hazel::Application* Hazel::onCreate() {
	return new Sandbox();
}
