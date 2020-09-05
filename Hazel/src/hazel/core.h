#pragma once

#ifdef HZ_PLATFORM_WIN 
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define ASSERT(x, ...) { if ((!x)) { CORE_LOG_ERR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CORE_ASSERT(x, ...) { if (!(x)) { CORE_LOG_ERR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif // HZ_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)