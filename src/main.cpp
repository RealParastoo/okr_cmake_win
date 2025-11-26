#ifdef ENABLE_EXTRA
#pragma message("ENABLE_EXTRA is visible in main.cpp")
#else
#pragma message("ENABLE_EXTRA is NOT visible in main.cpp")
#endif

#include <iostream>
#include "greet/greet.h"

int main() {
    std::cout << greet() << "\n";

#ifdef ENABLE_EXTRA
    std::cout << greet_extra() << "\n";
#endif

    return 0;
}
