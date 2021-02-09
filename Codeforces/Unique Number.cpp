#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string dp[55];

bool ls(string a, string b){
	if(a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

void solve(){
	int x;
	cin >> x;
	rep(i, 55) dp[i] = "";
	repn(i, 1, 10){
		for(int tot = 55 - i; tot >= 0; tot--) if(dp[tot].size() || !tot){
			string nw = dp[tot];
			nw += to_string(i);
			if(ls(nw, dp[tot + i]) || !dp[tot + i].size()) dp[tot + i] = nw;
		}
	}
	cout << ((int)(dp[x].size()) ? dp[x] : "-1") << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
