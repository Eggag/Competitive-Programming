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

int dp[20][3];

struct ColorfulRoad{
	int getMin(string s){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		int n = s.size();
		rep(i, n){
			if(s[i] == 'R') s[i] = '0';
			if(s[i] == 'G') s[i] = '1';
			if(s[i] == 'B') s[i] = '2';
		}
		rep(i, 20) rep(j, 3) dp[i][j] = 1e9;
		dp[1][0] = 0;
		repn(i, 2, n + 1){
				int prev = (s[i - 1] - '0') - 1;
				if(prev == -1) prev = 2;
				rep(j, i){
					dp[i][s[i - 1] - '0'] = min(dp[i][s[i - 1] - '0'], dp[j][prev] + (i - j) * (i - j));
			}
		}
		return (dp[n][s[n - 1] - '0'] == 1e9 ? -1 : dp[n][s[n - 1] - '0']);
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/              
