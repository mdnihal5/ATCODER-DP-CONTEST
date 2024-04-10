#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1e5 + 5;
vector<int>dp(N, INT_MAX);

int32_t main()
{
    int n, k; cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    dp[0] = 0;

    // base case initially we don't need any const

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            // we have k moves we can jump i+1,i+2,i+3,....i+k jumps pick the best one
            dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
        }
    }
    cout << dp[n - 1];
}


// Memoization : https://atcoder.jp/contests/dp/submissions/48412563
// Tabulation  : https://atcoder.jp/contests/dp/submissions/48422928
