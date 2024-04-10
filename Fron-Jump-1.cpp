#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1e5 + 5;
vector<int>dp(N, INT_MAX);

int32_t main()
{
    int n; cin >> n;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    dp[0] = 0, dp[1] = abs(v[1] - v[0]);
  
    // base case initially we don't need any const
    // for dp[1] there is only one move , so cost is |v[1]-v[0|
  
    for (int i = 1; i < n; i++) {
        // for every move we have two options jump 1 move or jump 2 moves
        dp[i] = min(dp[i], dp[i - 1] + abs(v[i] - v[i - 1]));
        dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
    }
    cout << dp[n - 1];
    
}

// memoizatoin code : https://atcoder.jp/contests/dp/submissions/48412677
// tabulation code  : https://atcoder.jp/contests/dp/submissions/48422790
