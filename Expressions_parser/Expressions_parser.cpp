#include <iostream>
#include <string>


float recur(const std::string* input, const int beg, const int end);

int main() {
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
            std::cout << "\n= " << recur(&input, 0, input.length() - 1);

        }

    } while (!exit);

    std::cout << "\nExited\n\n";
    return 0;
} 

float recur(const std::string* input, const int beg, const int end) {
    if (input->empty()) {
        // do something to manage the error
    }

    const char ops[4] = { '+','-','*','/' };
    int opPos = -1;
    int cur = beg;
    int b = beg;
    int e = end;
    const int len = e - b + 1;
    int lastHPrioOp = -1;

    cur--;
    // look for lowest priority operators first
    do {
        ++cur;
        if (!std::isdigit((*input)[cur])) {
            if ((*input)[cur] == '(') {    // skip to the matching brace and go on searching
                int braces = 1;
                int startBrace = cur;
                int endBrace = startBrace;
                do {
                    if ((*input)[++cur] == ')') {
                        braces--;
                        if (braces == 0) {
                            endBrace = cur;
                        }
                    }
                    else if ((*input)[cur] == '(') {
                        braces++;
                    }
                } while ((braces > 0) && (cur < e));
                if (startBrace == endBrace) {
                    // the expression is invalid
                }
                else if ((startBrace == b) && (endBrace == e)) {
                    // reset state
                    cur = ++b;
                    e--;
                    continue;
                }
            }
            else if ((*input)[cur] == '+' || (*input)[cur] == '-') {  // found a low priority operator -> exit loop
                opPos = cur;
                break;
            }
            else if ((*input)[cur] == '*' || (*input)[cur] == '/') {    // found a high priority operator -> continue searching
                lastHPrioOp = cur;
            }
        }
    } while (cur < e);

    if (cur == e) {
        if (lastHPrioOp == -1 && opPos == -1)       // if we are in the base case
            return std::stof(input->substr(beg, end - beg + 1));
        else if (lastHPrioOp != -1 && opPos == -1)  // if there was no low priority operator
            opPos = lastHPrioOp;
    }

    float A = recur(input, b, opPos - 1);
    float B = recur(input, opPos + 1, e);

    switch ((*input)[opPos]) {
    case '+':
        return A + B;

    case '-':
        return A - B;

    case '*':
        return A * B;

    case '/':
        return A / B;

    default:
        break;
    }
    return 0.0;
}
