#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int dp[50], dp1[50];

struct BadNeighbors{
        int maxDonations(vi d){
                ios_base::sync_with_stdio(false);
                int n = d.size();
                cin.tie(0);
                dp[0] = d[0];
                dp1[0] = 0;
                dp[1] = max(d[0], d[1]);
                dp1[1] = d[1];
                repn(i, 2, n){
                        dp[i] = max(dp[i - 1], dp[i - 2] + d[i]);
                        dp1[i] = max(dp1[i - 1], dp1[i - 2] + d[i]);
                }
                return max(dp[n - 2], dp1[n - 1]);
        }
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/
