#include "Solution224.h"
#include <stack>
#include <vector>

int Solution224::calculate(string s) {
    int lens = s.size();
    stack<int> stk;
    int res = 0;
    vector<int> count;
    int flag = 0;
    for (int i = 0; i < lens; i++) {
        if (s[i] == ')') {
            while (stk.top() != '(') {
                if (stk.top() == '+') {
                    flag = 1;
                    stk.pop();
                }
                else if (stk.top() == '-') {
                    flag = 2;
                    stk.pop();
                }
                else {
                    if (flag == 0) {
                        count.push_back(s[i]-'0');
                    }
                    else if (flag == 1) {
                        int num1 = count.back();
                        res += stk.top() + num1;
                        stk.pop();
                        count.pop_back();
                        flag = 0;
                    }
                    else if (flag == 2) {
                        int num1 = count.back();
                        res += stk.top() - num1;
                        stk.pop();
                        count.pop_back();
                        flag = 0;
                    }
                }
            }
            stk.pop();
            stk.push(res);
        }
        else if (s[i] == ' ') {
            continue;
        }
        else if (s[i] == '+' || s[i] == '-') {
            stk.push(s[i]);
        } else {
            stk.push(s[i]-'0');
        }
    }
    flag = 0;
    res = 0;
    while (!stk.empty()) {
        if (stk.top() == '+') {
            flag = 1;
            stk.pop();
        }
        else if (stk.top() == '-') {
            flag = 2;
            stk.pop();
        }
        else {
            if (flag == 0) {
                count.push_back(stk.top());
                stk.pop();
            }
            else if (flag == 1) {
                int num1 = count.back();
                res += stk.top() + num1;
                stk.pop();
                count.pop_back();
                flag = 0;
            }
            else if (flag == 2) {
                int num1 = count.back();
                res += stk.top() - num1;
                stk.pop();
                count.pop_back();
                flag = 0;
            }
        }
    }
    if (!count.empty()) {
        res += count.back();
    }
    return res;
}