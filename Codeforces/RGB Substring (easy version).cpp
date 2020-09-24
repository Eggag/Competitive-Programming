#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, k;
	cin >> n >> k;
	string s1;
	cin >> s1;
	int mn = 1e9;
	string s;
	rep(i, n - k + 1){
		s = s1;
		int ans = 0;
		if(s[i] != 'R') ans++;
		s[i] = 'R';
		repn(j, i + 1, i + k){
			int f = 0;
			if(s[j] == 'R' && s[j - 1] == 'B') f = 1;			
			if(s[j] == 'G' && s[j - 1] == 'R') f = 1;
			if(s[j] == 'B' && s[j - 1] == 'G') f = 1;
			if(!f){
				ans++;
				//change the s[j]
				if(s[j - 1] == 'R') s[j] = 'G';
				if(s[j - 1] == 'G') s[j] = 'B';
				if(s[j - 1] == 'B') s[j] = 'R';
			}
		}
		mn = min(ans, mn);
	}
	rep(i, n - k + 1){
		s = s1;
		int ans = 0;
		if(s[i] != 'G') ans++;
		s[i] = 'G';
		repn(j, i + 1, i + k){
			int f = 0;
			if(s[j] == 'R' && s[j - 1] == 'B') f = 1;			
			if(s[j] == 'G' && s[j - 1] == 'R') f = 1;
			if(s[j] == 'B' && s[j - 1] == 'G') f = 1;
			if(!f){
				ans++;
				//change the s[j]
				if(s[j - 1] == 'R') s[j] = 'G';
				if(s[j - 1] == 'G') s[j] = 'B';
				if(s[j - 1] == 'B') s[j] = 'R';
			}
		}
		mn = min(ans, mn);
	}
	rep(i, n - k + 1){
		s = s1;
		int ans = 0;
		if(s[i] != 'B') ans++;
		s[i] = 'B';
		repn(j, i + 1, i + k){
			int f = 0;
			if(s[j] == 'R' && s[j - 1] == 'B') f = 1;			
			if(s[j] == 'G' && s[j - 1] == 'R') f = 1;
			if(s[j] == 'B' && s[j - 1] == 'G') f = 1;
			if(!f){
				ans++;
				//change the s[j]
				if(s[j - 1] == 'R') s[j] = 'G';
				if(s[j - 1] == 'G') s[j] = 'B';
				if(s[j - 1] == 'B') s[j] = 'R';
			}
		}
		mn = min(ans, mn);
	}
	cout << mn << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
