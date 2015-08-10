#include <iostream>

using namespace std;

// intorduction to algorithm, NP-1
/*
void cut() {
    int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };    
    int r[100] {0};
    int v = 0;
    int n = 30;
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = 1; j < i;j++) {
            tmp += r[j];
        }
    }
}
*/

void npstudy() {
    int a[3] = { 1, 3, 5 }, sum = 11, cent = 0, dp[12];
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) dp[i] = i;//我们假设存在1元的硬币那么i元最多只需要i枚1元硬币，当然最好设置dp[i]等于无穷大  

    for (int i = 1; i <= sum; i++){
        for (int j = 0; j < 3; j++){
            if (i >= a[j] && dp[i - a[j]] + 1 < dp[i]){
                dp[i] = dp[i - a[j]] + 1;
            }
        }
    }
    cout << dp[sum] << endl;
    
}