#pragma once
#include "hazel/core.h"

namespace Hazel {

	struct MousePos
	{
		float x;
		float y;
		MousePos(float x, float y) : x(x), y(y) {}
		MousePos(double x, double y) : x((float)x), y((float)y) {}
	};

	// Interface: used for delivering event statuses or it's positions on the window. 
	class HAZEL_API Input 
	{

	public:
		virtual bool isKeyPressed(int keycode) = 0;
		virtual bool isMousePressed(int button) = 0;
		virtual MousePos getMousePosition() = 0;

	};

}