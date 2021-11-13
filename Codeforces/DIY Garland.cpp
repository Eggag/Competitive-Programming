#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n - 1);
	rep(i, n - 1) cin >> a[i], a[i]--;
	vi vis(n, 0);
	int rt = a[0];
	vis[rt] = 1;
	int nxt = n - 1;
	if(vis[nxt]) nxt--;
	vector<pi> ed;
	repn(i, 1, n - 1){
		if(a[i] == nxt){
			ed.pb(mp(a[i - 1], a[i]));
			vis[nxt] = 1;
			nxt--;
			if(nxt < 0) break;
			while(nxt >= 0 && vis[nxt]) nxt--;
			if(nxt < 0) break;
		}
		else if(vis[a[i]]){
			ed.pb(mp(a[i - 1], nxt));
			vis[nxt] = 1;
			nxt--;
			if(nxt < 0) break;
			while(nxt >= 0 && vis[nxt]) nxt--;
			if(nxt < 0) break;
		}
		else{
			vis[a[i]] = 1;
			ed.pb(mp(a[i], a[i - 1]));
		}
	}
	rep(i, n) if(!vis[i]) ed.pb(mp(a[n - 2], i));
	cout << rt + 1 << '\n';
	for(pi x : ed) cout << x.fi + 1 << " " << x.se + 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
