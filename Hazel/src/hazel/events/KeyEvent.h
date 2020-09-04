#pragma once

#include "Event.h"

namespace Hazel {

	class HAZEL_API KeyEvent : public Event 
	{

	protected:
		int m_keyCode;

	protected:
		KeyEvent(int keyCode) : m_keyCode(keyCode) {}

	public:
		inline int getKeyCode() const {
			return m_keyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{

	private:
		int m_repeatCount;

	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

	public:
		inline int getRepeatCount() const { return m_repeatCount; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent 
	{

	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

	public:
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};

	class HAZEL_API KeyTypedEvent : public KeyEvent
	{

	public:
		KeyTypedEvent(int keyCode) : KeyEvent(keyCode) {}

	public:
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};

}