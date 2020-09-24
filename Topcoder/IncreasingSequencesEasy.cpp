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
const int MOD = 998244353;

int dp[305][10005];

struct IncreasingSequencesEasy{
        int count(vi l, vi r){
                ios_base::sync_with_stdio(false);
                cin.tie(0);
            	int n = l.size();
		repn(i, l[0], r[0] + 1) dp[0][i] = 1;
        	repn(i, 1, n){ 
                        int sum = 0;
            	        rep(j, l[i]) sum = (sum + dp[i - 1][j]) % MOD;
                    	dp[i][l[i]] = sum;
          	        repn(k, l[i] + 1, r[i] + 1){
                                dp[i][k] = (dp[i][k - 1] + dp[i - 1][k - 1]) % MOD;
                        }
        	}
		int ans = 0;
        	rep(i, 10005){
        		ans = (ans + dp[n - 1][i]) % MOD;
        	}
        	return ans;
        }
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/