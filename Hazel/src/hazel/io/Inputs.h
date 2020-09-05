#pragma once
#include "Input.h"

#include "platform/windows/io/WindowsInput.h"

#ifdef HZ_PLATFORM_WIN
#define HZ_INPUT new WindowsInput()
#endif // HZ_PLATFROM_WIN

namespace Hazel {

	Input* input = nullptr;

	// Utility class: Used to deliver Input interface with a platform-specific instance.
	class HAZEL_API Inputs {

	public:
		static Input* getInput() {
			if (input == nullptr) {
				input = HZ_INPUT;
			}
			return input;
		}
	};

}