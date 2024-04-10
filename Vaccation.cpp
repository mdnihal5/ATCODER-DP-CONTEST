#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef unsigned long long ull;
#define endl "\n"
#define int long long
#define Lint int64_t
#define sz(a) (int)a.size()
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define rep(x,n) for (int i = x; i <=(n); i++)
#define print(x) (x)?cout<<"YES\n":cout<<"NO\n";
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e6 + 7;

template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a) {in >> a.first >> a.second; return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a) {os << a.first << " " << a.second; return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (auto &i : a) {os << i << " ";} return os;}


#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/



void __solve(int testcases) {

    int n; cin >> n;
    vi swim(n), catch_bugs(n), do_homework(n);
    for (int i = 0; i < n; i++) {
        cin >> swim[i] >> catch_bugs[i] >> do_homework[i];
    }

    int dp[n + 1][2][2][2];

    memset(dp, -1, sizeof(dp));

    function<int(int, int, int, int)>solve = [&](int i, int day1, int day2, int day3) {
        if (i >= n) {
            return 0LL;
        } else if (dp[i][day1][day2][day3] != -1) {
            return dp[i][day1][day2][day3];
        }
        int ans = -inf;
        if (day1) {
            // if we choosed to swim earlier we have two other choices
            ans = max(ans, solve(i + 1, 0, 1, 0) + catch_bugs[i]);
            ans = max(ans, solve(i + 1, 0, 0, 1) + do_homework[i]);
        } else {
            // if we did any other activity we can swim this time
            ans = max(ans, solve(i + 1, 1, 0, 0) + swim[i]);
        }
        if (day2) {
            // if we choosed to catch bugs earlier we have two other choices
            ans = max(ans, solve(i + 1, 1, 0, 0) + swim[i]);
            ans = max(ans, solve(i + 1, 0, 0, 1) + do_homework[i]);
        } else {
            // if we did any other activity we can catch bugs this time
            ans = max(ans, solve(i + 1, 0, 1, 0) + catch_bugs[i]);
        }
        if (day3) {
            // if we choose to do home work earlier we have two other choices
            ans = max(ans, solve(i + 1, 1, 0, 0) + swim[i]);
            ans = max(ans, solve(i + 1, 0, 1, 0) + catch_bugs[i]);
        } else {
            // if we did any other activity we can do homework this time
            ans = max(ans, solve(i + 1, 0, 0, 1) + do_homework[i]);
        }
        return dp[i][day1][day2][day3] = ans;
    };

    cout << solve(0, 0, 0, 0);
}



/*============================================= MAIN =============================================*/

int32_t  main()
{
    Md_Nihal;
    int testcases = 1;    //cin >> testcases;
    for (int i = 0; i < testcases; cout << endl) __solve(++i);
}

// memoization  :-  https://atcoder.jp/contests/dp/submissions/48886003
// tabulation   :- https://atcoder.jp/contests/dp/submissions/48886278
