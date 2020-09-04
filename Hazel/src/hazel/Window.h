#pragma once 

#include "hzpch.h"

#include "hazel/core.h"
#include "hazel/events/Event.h"

namespace Hazel {

	struct WindowProps
	{
		std::string _title;
		unsigned int _width, _height;

		WindowProps(const std::string& title = "Hazel Engine", 
			unsigned int width = 1280,
			unsigned int height = 720)
			: _title(title), _width(width), _height(height) 
		{
		}

	};

	// interface that represents a desktop system based Window.
	class HAZEL_API Window 
	{

	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& windowProps = WindowProps());

	};

}