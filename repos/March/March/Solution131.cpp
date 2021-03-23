#include "Solution131.h"

void Solution131::dfs(string s, int i, int n) {
    if (i == n) {
        res.push_back(ans);
        return;
    }
    for (int j = i; j < n; j++) {
        if (f[i][j]) {
            ans.push_back(s.substr(i, j - i + 1));
            dfs(s, j + 1, n);
            ans.pop_back();
        }
    }

}

vector<vector<string>> Solution131::partition(string s) {
    int n = s.size();
    f.assign(n, vector<bool>(n, true));
    /*
    从前向后进行预处理得到回文子序列，会有一些不对的地方
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = ((s[i] == s[j]) && f[i + 1][j - 1]);
        }
    }*/

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }

    dfs(s, 0, n);
    return res;
}