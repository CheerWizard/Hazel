// Hazel pre-compiled header, used to deliver the common files or libraries to all parts of Hazel project.
#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <chrono>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "hazel/logger/Log.h"

#ifdef  HZ_PLATFORM_WIN
	#include <Windows.h>
#endif //  HZ_PLATFORM_WIN

