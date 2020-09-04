#pragma once
#include "hzpch.h"
#include "app/app.h"

#ifdef HZ_PLATFORM_WIN

extern Hazel::Application* Hazel::onCreate();

int main(int argc, char** argv) {
	// TODO: should move it in a separate init file. 
	// We should not init logging system here.
	Hazel::Log::init();
	// logging start messages.
	CORE_LOG_WARN("Initialized!");
	CLIENT_LOG_INFO("Hello!");
	// init hazel application.
	auto app = Hazel::onCreate();
	app->run();
	delete app;
}

#endif