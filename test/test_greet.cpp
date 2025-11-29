#include <iostream>
#include "greet/greet.h"

int main() {
    std::string message = greet();

    if (message != "Hello from greet()") {
        std::cerr << "Test FAILED: greet() returned: " << message << "\n";
        return 1; // non-zero = test failed
    }

#ifdef ENABLE_EXTRA
    std::string extra = greet_extra();
    if (extra != "Extra greeting enabled") {
        std::cerr << "Test FAILED: greet_extra() returned: " << extra << "\n";
        return 1;
    }
#endif

    std::cout << "All tests passed.\n";
    return 0;
}
