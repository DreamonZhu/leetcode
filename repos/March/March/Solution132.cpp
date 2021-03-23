#include "Solution132.h"

int Solution132::dfs(string s, int i, int lens) {
    // ���ַ�����ȱ�ݣ����磺"aaabaa" �����2���ָʽ��: aaa b aa ����ʵ���ٵ��� a aabaa �����1
    if (i == lens) {
        return nums;
    }
    int j = lens - 1;
    while (j > i && !f[i][j]) {
        j--;
    }
    if (j < lens - 1 && j >= i) {
        nums++;
        dfs(s, j + 1, lens);
    }
    return nums;
}

int Solution132::minCut(string s) {
    n = s.size();
    f.assign(n, vector<int>(n, 1));
    for (int i = n - 1; i >= 0; i --) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    nums = 0;
    nums = dfs(s, 0, n);
    return nums;
}