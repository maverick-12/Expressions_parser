#include <iostream>
#include <string>


float recur(std::string input);

int main()
{
    bool exit = false;
    std::string input;

    do {
        input.clear();
        std::cout << "\n\nInsert expression\n";
        std::getline(std::cin, input);
        if (input.compare("quit") == 0) {
            exit = true;
        }
        else {
            input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
            std::cout << "\n= " << recur(input);
            
        }

    } while (!exit);

    std::cout << "\nExited\n\n";
    return 0;
}

float recur(std::string input) {
    if (input.empty()) {
        // do something to manage the error
    }

    int len = input.length();
    int opPos = -1;
    int cur;
    char ops[4] = { '+','-','*','/' };
    // look for ops
    for (int i = 0; i < 4; i++) {
        cur = 0;
        do {
            if (input[cur] == ops[i]) {
                opPos = cur;    // save 
                i = 4;          // to break the outer loop and to know an op was found
                break;
            }
            cur++;
        } while (cur < len);
    }

    // if we are in the base case
    if (cur == len) {
        return std::stof(input);
    }

    float a = recur(input.substr(0, opPos));
    float b = recur(input.substr(opPos + 1, len));

    switch (input[opPos]) {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    default:
        break;
    }
    return 0.0;
}
