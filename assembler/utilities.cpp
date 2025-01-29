#include "utilities.hpp"

void toPostfix(std::ifstream& in, std::ostream& out) {
    stack<String> myStack;
    String left, right, sign, currentToken;
    char token[300];

    while (!in.eof()) {
        in >> token;
        currentToken = String(token);

        if (in.eof()) {
            break;
        }

        if (currentToken == ";") {
            out << myStack.top();
            out << ";";
            out << "\n";
            myStack = stack<String>();
        } else if (currentToken == ")") {
            right = myStack.pop();
            sign = myStack.pop();
            left = myStack.pop();
            myStack.push(left + right + sign);
        } else {
            if (currentToken != "(") {
                myStack.push(currentToken + ' ');
            }
        }
    }
}
void toAssembly(std::ifstream& in, std::ostream& out) {
    stack<String> myStack;
    String left, right, op, temp, currentToken;
    int tempNum = 1;

    while (!in.eof()) {
        if (!in.eof()) {
            currentToken = getToken(in);
        } else {
            break;
        }

        if (currentToken == ";") {
            temp = "temp" + intToString(tempNum++);
            out << "   ST    " << temp << "\n"; 
            out << "=============================================" << "\n"; 
            tempNum = 1;
        }

        if (!in.eof() && currentToken != "+" && currentToken != "-" && currentToken != "*" && currentToken != "/") {
            myStack.push(currentToken);
        } else if (!in.eof()) {
            right = myStack.pop();
            left = myStack.pop();

            out << "   LD    " << left << "\n";

            op = getOperator(currentToken);
            out << op << right << "\n";
            
            temp = "temp" + intToString(tempNum++);
            myStack.push(temp);

            out << "   ST    " << temp << "\n";
        }
    }

   
}



String getOperator(const String& op)
{
    switch (op[0]) {
        case '+':
            return "\tAdd\t";
            break;
        case '-':
            return "\tSubtrack\t";
            break;
        case '*':
            return "\tMultiplay\t";
            break;
        case '/':
            return "\tDivide\t";
            break;
        default:
            return "\tN/A\t";
    }
}

String intToString(int x) {
    if (!x) {
        return "0";
    }

    String result;

    do {
        result += (x % 10 + 48);
        x /= 10;
    } while (x > 0);

    return result;
}

String getToken(std::ifstream& in) {
    String result;
    char token = '\0';

    while (token != ' ' && !in.eof()) {
        in.get(token);

        if (token == ';') {
            return ";";
        } else if (token != ' ') {
            result += token;
        }
    }

    return result;
}
    