#include <Identifier.h>

using namespace dex;

int main() {
    Identifier test1;
    Identifier test2;
    Identifier test3;
    Identifier test4;

    try {
        test1 = "nr";
        std::cout << "Test 1 Passed: Created Identifier " << test1 << "\n";
    }
    catch (std::invalid_argument e) {
        std::cout << "Test 1 Failed: " << e.what() << "\n";
    }

    Identifier::setDefaultNamespace("default");
    try {
        test2 = "nr";
        std::cout << "Test 2 Passed: Created Identifier " << test2 << "\n";
    }
    catch (std::invalid_argument e) {
        std::cout << "Test 2 Failed: " << e.what() << "\n";
    }

    try {
        test3 = "n:r:e";
        std::cout << "Test 3 Passed: Created Identifier " << test3 << "\n";
    }
    catch (std::invalid_argument e) {
        std::cout << "Test 3 Failed: " << e.what() << "\n";
    }

    try {
        test4 = "name:444";
        std::cout << "Test 4 Passed: Created Identifier " << test4 << "\n";
    }
    catch (std::invalid_argument e) {
        std::cout << "Test 4 Failed: " << e.what() << "\n";
    }

    std::cout << "All tests passed!\n";
}
