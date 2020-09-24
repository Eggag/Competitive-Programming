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

int dp[55][2];

struct ZigZag{
	int longestZigZag(vector<int> sequence){
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		//freopen("input.in", "r", stdin);
        	//freopen("output.out", "w", stdout);
		dp[0][0] = dp[0][1] = 1;
		int ans = 1;
		repn(i, 1, sequence.size()){
			rep(j, i){
				if(sequence[i] > sequence[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
				if(sequence[i] < sequence[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			}
			ans = max(ans, max(dp[i][1], dp[i][0]));
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
