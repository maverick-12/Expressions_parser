#include <iostream>
#include <string>

int main()
{
    bool exit = false;
    std::string input;

    do {
        input = "";
        std::cout << "\n\nInsert expression\n";
        std::cin >> input;
        std::cout << input;
        if (input.compare("\nquit")) {
            std::cout << "\nExiting..";
            exit = true;
        }
        else {

        }

    } while (!exit);

    std::cout << "\nExited";
    return 0;
}
