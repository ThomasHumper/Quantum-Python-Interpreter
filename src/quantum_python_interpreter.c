sudo apt install python3-dev

#include <iostream>
#include <sstream>
#include <string>
#include <map>

std::map<std::string, int> vars;

int evalExpression(const std::string& expr) {
    std::stringstream ss(expr);
    int result;
    ss >> result;

    char op;
    int value;

    while (ss >> op >> value) {
        if (op == '+') result += value;
        else if (op == '-') result -= value;
        else if (op == '*') result *= value;
        else if (op == '/') result /= value;
    }

    return result;
}

void execute(const std::string& line) {
    if (line.find("print") == 0) {
        std::string expr = line.substr(6);
        std::cout << evalExpression(expr) << std::endl;
    } else if (line.find("=") != std::string::npos) {
        auto pos = line.find("=");
        std::string name = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        vars[name] = evalExpression(value);
    } else {
        std::cout << "Unknown command\n";
    }
}

int main() {
    std::string line;

    std::cout << "Toy Python Interpreter (type 'exit')\n";

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, line);

        if (line == "exit") break;

        execute(line);
    }
}
