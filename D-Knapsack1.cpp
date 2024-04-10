#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int n, w; cin >> n >> w;
    vector<int>val(n), weight(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> val[i];
    vector<vector<int>>dp(n + 1, vector<int>(w + 1, -1));

    function<int(int, int)>helper = [&](int i, int wt) {
        if (i >= n) return 0LL; // base case
        else if (dp[i][wt] != -1) return dp[i][wt];  // memoization
        if (wt >= weight[i]) {
            int x = val[i] + helper(i + 1, wt - weight[i]);  // pick this weight
            int y = helper(i + 1, wt);     // leave this weight
            return dp[i][wt] = max({dp[i][wt], x, y});
        }
        else return dp[i][wt] = max(dp[i][wt], helper(i + 1, wt));
    };

    cout << helper(0, w);

}


// https://atcoder.jp/contests/dp/tasks/dp_d
// memoization : https://atcoder.jp/contests/dp/submissions/48966358
// tabulation :  https://atcoder.jp/contests/dp/submissions/48966331
