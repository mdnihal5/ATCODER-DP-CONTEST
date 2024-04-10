#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
const int MAX = 1e14;
int32_t main()
{
    int n, w; cin >> n >> w;
    vector<int>val(n), weight(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> val[i];
    int sum = accumulate(all(val), 0ll);
    vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1));
    // dp for minimum we need to pick to maxi val (x)
    function<int(int, int)>helper = [&](int i, int wt) {
        if (wt == 0) return 0ll;
        else if (i >= n) return MAX; // base case
        else if (dp[i][wt] != -1) return dp[i][wt];  // memoization
        if (wt >= val[i]) {
            int x = weight[i] + helper(i + 1, wt - val[i]);  // pick this val
            int y = helper(i + 1, wt);     // leave this val
            return dp[i][wt] = min(x, y);
        }
        else return dp[i][wt] = helper(i + 1, wt);
    };

    while (helper(0, sum) > w) sum--;
    cout << sum;

}

// https://atcoder.jp/contests/dp/tasks/dp_e
// memoization : https://atcoder.jp/contests/dp/submissions/48966501
// tabulation : https://atcoder.jp/contests/dp/submissions/48966572
