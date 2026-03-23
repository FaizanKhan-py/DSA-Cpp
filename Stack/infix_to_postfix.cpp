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

    bool isempty() {
        return top == -1;
    }

    bool isfull() {
        return top == size - 1;
    }

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

class InfixToPostfix {
private:
    string infix;
    string postfix;

public:
    InfixToPostfix() {
        infix = "";
        postfix = "";
    }

    InfixToPostfix(string expression) {
        infix = expression;
        postfix = "";
    }

    void readInfix() {
        cout << "Enter the infix expression: ";
        cin >> infix;
    }

    void showInfix() {
        cout << "Infix Expression: " << infix << endl;
    }

    bool isOperand(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
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

    bool isvalidity() {
        Stack<char> stk;

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix[i];

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

    void showPostfix() {
        cout << "Postfix Expression: " << postfix << endl;
    }

    void convertToPostfix() {
        Stack<char> st;

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                postfix += c;
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
                    postfix += st.peek();
                    st.pop();
                }
                st.pop();
            }

            else {
                while (!st.isempty() &&
                    (precedence(c) < precedence(st.peek()) ||
                        precedence(c) == precedence(st.peek()))) {
                    postfix += st.peek();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.isempty()) {
            postfix += st.peek();
            st.pop();
        }
    }


    int EvaluatePostfix() {
        Stack<int> opndStack;

        for (int i = 0; i < postfix.length(); ++i) {
            char symbol = postfix[i];

            if (symbol >= '0' && symbol <= '9') {
                opndStack.push(symbol - '0');
            }
            else {
                int opnd2 = opndStack.pop();
                int opnd1 = opndStack.pop();
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
                    break;
                case '^':
                    result = pow(opnd1, opnd2);
                    break;
                }

                opndStack.push(result);
            }
        }

        return opndStack.pop();
    }
};










int main() {
    string infix = "[(-3-1+3*3)]";
    bool flag = true;

    InfixToPostfix obj(infix);

    if (obj.isvalidity()) {
        obj.showInfix();
        obj.convertToPostfix();
        obj.showPostfix();

        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
                flag = false;
                break;
            }
        }
        if (flag) {
            int result = obj.EvaluatePostfix();
            cout << "Result of postfix evaluation: " << result << endl;
        }
    }

    return 0;
}

