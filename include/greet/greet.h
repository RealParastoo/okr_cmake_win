#pragma once
#include <string>

std::string greet();

#ifdef ENABLE_EXTRA
std::string greet_extra();
#endif