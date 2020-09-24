#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s, t;
	cin >> s >> t;
	vi p[30];
	rep(i, s.size()) p[s[i] - 'a'].pb(i);
	rep(i, t.size()) if(!p[t[i] - 'a'].size()){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	int pos = -1;
	rep(i, t.size()){
		int ps = lb(all(p[t[i] - 'a']), pos + 1) - p[t[i] - 'a'].begin();
		if(ps == (p[t[i] - 'a'].size()) || p[t[i] - 'a'][ps] <= pos){
			ans += (s.size() - pos) + (p[t[i] - 'a'][0]);
			pos = p[t[i] - 'a'][0];
		}
		else{
			ans += p[t[i] - 'a'][ps] - pos;
			pos = p[t[i] - 'a'][ps];
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
