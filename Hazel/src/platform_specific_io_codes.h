#pragma once
#ifdef HZ_PLATFORM_WIN
// Windows specific library.
#include "platform/windows/io/KeyBoardCodes.h"
#elif HZ_PLATFORM_WIN32
// Win32 specific library.
#include "platform/win32/io/KeyBoardCodes.h"
#endif
#include "hazel/io/MouseCodes.h"