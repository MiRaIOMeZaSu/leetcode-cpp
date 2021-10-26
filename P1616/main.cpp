#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int target, size;
    cin >> target >> size;
    int costs[size];
    int vals[size];
    for (int i = 0; i < size; i++) {
        cin >> costs[i];
        cin >> vals[i];
    }
    int dp[target + 1];
    memset(dp, 0, sizeof(int) * (target + 1));
    for (int i = 0; i < size; i++) {
        int cost = costs[i];
        int val = vals[i];
        for (int j = cost; j <= target; j++) {
            // 完全背包的特点
//            if (dp[j - cost] != 0 || j - cost == 0) {
                dp[j] = max(dp[j], dp[j - cost] + val);
//            }
        }
    }
    cout << dp[target] << endl;
    return 0;
}
