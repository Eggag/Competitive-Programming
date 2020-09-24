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

int query(vi a){
	if(!a.size()) return 0;
	cout << "? " << a.size();
	for(int x : a) cout << " " << x;
	cout << endl;
	int res;
	cin >> res;
	return res;
}

vi v[1005];
map<int, int> vis;

void solve(){
	int n, k;
	cin >> n >> k;
	vi comp;
	repn(i, 1, n + 1) comp.pb(i);
	rep(i, k) v[i].clear();
	vis.clear();
	rep(i, k){
		int c;
		cin >> c;
		rep(j, c){
			int x;
			cin >> x;
			v[i].pb(x);
		}
	}
	int mx = query(comp);
	while(comp.size() > 1){
		vi comp1, comp2;
		rep(i, comp.size() / 2) comp1.pb(comp[i]);
		repn(i, comp.size() / 2, comp.size()) comp2.pb(comp[i]);
		if(query(comp1) == mx) comp = comp1;
		else comp = comp2;
	}
	//comp[0] is a good index
	vi ans;
	rep(i, k){
		int f = 1;
		rep(j, v[i].size()) if(comp[0] == v[i][j]){
			f = 0;
			break;
		}
		if(f) ans.pb(mx);
		if(!f){
			//special case
			vi b;
			rep(j, v[i].size()) vis[v[i][j]] = 1;
			repn(j, 1, n + 1) if(!vis[j]) b.pb(j);
			int mx1 = query(b);
			ans.pb(mx1);
		}
	}
	cout << "!";
	rep(i, ans.size()) cout << " " << ans[i];
	cout << endl;
	string s;
	cin >> s;
	if(s != "Correct") exit(0);
}

int main(){
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
	- Array bounds
	- Special cases
Be careful!
*/
