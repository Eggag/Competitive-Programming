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

void solve(){
	string s, t, p;
	cin >> s >> t >> p;
	int cnt = 0;
	rep(i, t.size()){
		if(t[i] == s[cnt]) cnt++;
	}
	if(cnt != s.size()){
		cout << "NO" << endl;
		return;
	}
	map<char, int> mp, mp1;
	rep(i, s.size()) mp[s[i]]++;
	rep(i, p.size()) mp[p[i]]++;
	rep(i, t.size()) mp1[t[i]]++;
	rep(i, t.size()){
		if(mp[t[i]] < mp1[t[i]]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
