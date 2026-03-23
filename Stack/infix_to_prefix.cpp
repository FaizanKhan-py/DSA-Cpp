#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int size;

public:
    Stack(int s = 100) {
        top = -1;
        size = s;
        arr = new T[size];
    }

    bool isempty() { return top == -1; }

    bool isfull() { return top == size - 1; }

    void push(T value) {
        if (isfull()) {
            cout << "Stack is Full" << endl;
        }
        else {
            arr[++top] = value;
        }
    }

    T pop() {
        if (isempty()) {
            return T();
        }
        else {
            return arr[top--];
        }
    }

    T peek() {
        if (!isempty()) {
            return arr[top];
        }
        return T();
    }

    ~Stack() {
        delete[] arr;
    }
};

class InfixToPrefix {
private:
    string infix;
    string prefix;

public:
    InfixToPrefix() {
        infix = "";
        prefix = "";
    }

    InfixToPrefix(string expression) {
        infix = expression;
        prefix = "";
    }

    void readInfix() {
        cout << "Enter the infix expression: ";
        cin >> infix;
    }

    void showInfix() {
        cout << "Infix Expression: " << infix << endl;
    }

    void showPrefix() {
        cout << "Prefix Expression: " << prefix << endl;
    }

    bool isOperand(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;
        else
            return -1;
    }

    bool validity() {
        Stack<char> stk;
        for (char ch : infix) {
            if (isOperand(ch) || isOperator(ch)) {
                continue;
            }
            else if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (stk.isempty()) {
                    cout << "Invalid Expression: Unmatched closing bracket!" << endl;
                    return false;
                }
                else {
                    char top = stk.pop();
                    if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                        cout << "Invalid Expression: Mismatched brackets!" << endl;
                        return false;
                    }
                }
            }
            else {
                cout << "Invalid Expression: Contains invalid characters!" << endl;
                return false;
            }
        }

        if (!stk.isempty()) {
            cout << "Invalid Expression: Unmatched opening bracket!" << endl;
            return false;
        }

        return true;
    }

    void convertToPrefix() {
        Stack<char> st;
        string reversedInfix = "";
        string reversedPrefix = "";

        for (int i = infix.length() - 1; i >= 0; i--) {
            char ch = infix[i];
            if (ch == '(')
                reversedInfix += ')';
            else if (ch == ')')
                reversedInfix += '(';
            else if (ch == '[')
                reversedInfix += ']';
            else if (ch == ']')
                reversedInfix += '[';
            else if (ch == '{')
                reversedInfix += '}';
            else if (ch == '}')
                reversedInfix += '{';
            else
                reversedInfix += ch;
        }

        for (int i = 0; i < reversedInfix.size(); i++) {
            char c = reversedInfix[i];
            if (isOperand(c)) {
                reversedPrefix += c;
            }
            else if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            else if (c == ')' || c == ']' || c == '}') {
                char openBracket = ' ';
                if (c == ')') {
                    openBracket = '(';
                }
                else if (c == ']') {
                    openBracket = '[';
                }
                else if (c == '}') {
                    openBracket = '{';
                }

                while (!st.isempty() && st.peek() != openBracket) {
                    reversedPrefix += st.pop();
                }
                st.pop();
            }
            else {
                while (!st.isempty() &&
                    (precedence(c) < precedence(st.peek()) || precedence(c) == precedence(st.peek()))) {
                    reversedPrefix += st.pop();
                }
                st.push(c);
            }
        }

        while (!st.isempty()) {
            reversedPrefix += st.pop();
        }

        for (int i = reversedPrefix.length() - 1; i >= 0; i--) {
            prefix += reversedPrefix[i];
        }
    }

    int evaluate() {
        Stack<int> opndStack;

        for (int i = prefix.length() - 1; i >= 0; --i) {
            char symbol = prefix[i];

            if (symbol >= '0' && symbol <= '9') {
                opndStack.push(symbol - '0');
            }
            else {
                int opnd1 = opndStack.pop();
                int opnd2 = opndStack.pop();
                int result = 0;

                switch (symbol) {
                case '+':
                    result = opnd1 + opnd2;
                    break;
                case '-':
                    result = opnd1 - opnd2;
                    break;
                case '*':
                    result = opnd1 * opnd2;
                    break;
                case '/':
                    result = opnd1 / opnd2;
                case '^':
                    result = pow(opnd1, opnd2);
                }

                opndStack.push(result);
            }
        }

        return opndStack.pop();
    }
};



int main() {
    string infix = "[(6-4)*(3+2)]";
    InfixToPrefix obj(infix);


    if (obj.validity()) {
        obj.showInfix();
        obj.convertToPrefix();
        obj.showPrefix();

        int result = obj.evaluate();
        cout << "Result of prefix evaluation: " << result << endl;
    }
    else {
        cout << "Invalid infix expression!" << endl;
    }

    return 0;
}



