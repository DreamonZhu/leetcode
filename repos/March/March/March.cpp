// March.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Solution131.h"
#include "Solution132.h"
#include "Solution224.h"
#include "Solution227.h"
#include "Solution706.h"
#include "Solution1318.h"
#include "Solution59.h"
#include "Solution150.h"

void test01() {
    // 测试字符串、单个字符以及字符指针
    char a = 'a';
    string str = "abc";
    cout << str.c_str() << endl;
    //cout << atoi(str.c_str()) << endl;
    const char* str1 = str.c_str();
    cout << str1 << endl;
    char* str2 = (char*)"D:\\file";
    cout << str2 << endl;
    cout << *str2 << endl;
    cout << *(str2 + 1) << endl;
    cout << *(str2 + 2) << endl;
    cout << *(str2 + 3) << endl;



}

int main()
{
    //std::cout << "Hello World!\n";

    //Solution131 sol;
    ////string str = "aab";
    //string str = "abbab";
    //vector<vector<string>> res = sol.partition(str);
    //for (auto& items : res) {
    //    for (auto& item : items) {
    //        cout << item << endl;
    //    }
    //}

    //Solution132 sol;
    //string str = "aab";
    ////string str = "a";
    ////string str = "ab";
    ////string str = "efe";
    //cout << sol.minCut(str) << endl;

    //Solution224 sol;
    ////string s = "1 + 1";
    //string s = " 2-1 + 2 ";
    //cout << sol.calculate(s) << endl;

    //Solution227 sol;
    //string s = "3+2*2";
    ////string s = " 3/2 ";
    ////string s = " 3+5 / 2 ";
    //cout << sol.calculate(s) << endl;

    /*Solution706 sol;
    sol.put(1, 1);
    cout << sol.get(1) << endl;
    sol.put(1, 3);
    cout << sol.get(1) << endl;
    sol.remove(1);
    cout << sol.get(1) << endl;*/

    //Solution1318 sol;
    ////int a = 2, b = 6, c = 5;
    //int a = 5, b = 2, c = 8;
    //cout << sol.minFlips(a, b, c) << endl;

    /*Solution59 sol;
    vector<vector<int>> mat = sol.generateMatrix(3);
    for (auto& items : mat) {
        for (auto& item : items) {
            cout << item << " ";
        }
        cout << endl;
    }*/

    //Solution150 sol;
    ////vector<string> tokens = { "2", "1", "+", "3", "*" };
    //vector<string>tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    //cout << sol.evalRPN(tokens) << endl;

    test01();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
