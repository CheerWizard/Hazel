#pragma once
#include "Event.h"

namespace Hazel {

	class HAZEL_API MouseMovedEvent : public Event
	{

	private:
		float m_mouseX, m_mouseY;

	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

	public:
		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	};

	class HAZEL_API MouseScrolledEvent : public Event
	{

	private:
		float m_xOffset, m_yOffset;

	public:
		MouseScrolledEvent(float xOffset, float yOffset) 
			: m_xOffset(xOffset), m_yOffset(yOffset) {}

	public:
		inline float getXOffset() const { return m_xOffset; }
		inline float getYOffset() const { return m_yOffset; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	};

	class HAZEL_API MouseButtonEvent : public Event
	{

	protected:
		int m_button;

	protected:
		MouseButtonEvent(int button) : m_button(button) {}

	public:
		inline int getButton() { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

	public:
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
	
	public:
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}