#include <Hazel.h>

#include "imgui.h"

class SandboxLayer : public Hazel::Layer {

public:

	virtual void onImGuiRender() override {
		ImGui::Begin("Sandbox");
		ImGui::Text("Hello from Sandbox!");
		ImGui::ColorEdit4("", new float[4]);
		ImGui::End();
	}

};

class Sandbox : public Hazel::Application {

public:
	Sandbox() {
		pushLayer(new SandboxLayer());
	}
	~Sandbox() {
	}

};

Hazel::Application* Hazel::onCreate() {
	return new Sandbox();
}
