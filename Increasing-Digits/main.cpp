#include <iostream>
#include <string.h>

using namespace std;

int solve(int n) {
    if(n ==1){
        return 9;
    }
    int dp[n + 1][10];
    // dp[a][b] : 对于长为a的序列,开头为a时的剩余可填充数量,最后对指定长度加和即可
    for (int i = 1; i < 10; i++) {
        // 此处是从第二开始
        dp[n - 1][i] = 0;
        dp[2][i] = 9 - i > 0 ? 9 - i : 0;
    }
    for (int i = 3; i <= n; i++) {
        for (int n = 1; n < 10; n++) {
            dp[i][n] = 0;
            for (int j = n + 1; j < 10; j++) {
                dp[i][n] += dp[i - 1][j];
            }
        }
    }
    int ret = 0;
    for (int i = 1; i < 10; i++) {
        ret += dp[n][i];
    }
    return ret;
}

int main() {
    cout<< solve(4);
    return 0;
}
