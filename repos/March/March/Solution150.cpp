#include "Solution150.h"
#include <stack>

bool Solution150::isNumber(string& token) {
    return !(token == "+" || token == "-" || token == "*" || token == "/");
}

int Solution150::evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (auto& item : tokens) {
        if (isNumber(item)) {
            stk.push(atoi(item.c_str()));
        }
        else {
            int right = stk.top();
            stk.pop();
            int left = stk.top();
            stk.pop();
            switch (item[0]) {
                case '+':
                    stk.push(left + right);
                    continue;
                case '-':
                    stk.push(left - right);
                    continue;
                case '*':
                    stk.push(left * right);
                    continue;
                case '/':
                    stk.push(left / right);
                    continue;
            }   
        }
    }
    return stk.top();
}