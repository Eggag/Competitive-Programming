#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	vector<string> s(3);
	rep(i, 3) cin >> s[i];
	ll sz = s[0].size();
	int best = -1;
	ll ans = -1;
	map<char, ll> mp;
	bool draw = 0;
	rep(i, 3){
		mp.clear();
		ll mx = 0;
		ll sz1 = sz;
		rep(j, s[i].size()) mp[s[i][j]]++;
		for(auto x : mp){
			mx = max(mx, x.se);
		}
		if(n == 1 && mx == sz) sz1--;
		mx = min(mx + n, sz1);
		if(mx == ans){
			draw = 1;
		}
		if(mx > ans){
			ans = mx;
			draw = 0;
			best = i;
		}
	}
	if(draw){
		cout << "Draw" << endl;
		return 0;
	}
	assert(best != -1);
	if(best == 0) cout << "Kuro" << endl;
	if(best == 1) cout << "Shiro" << endl;
	if(best == 2) cout << "Katie" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
