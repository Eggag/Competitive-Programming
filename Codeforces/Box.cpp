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

int v[100005], ns[100005];

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se < b.se;
}

void solve(){
	int n;
	cin >> n;
	vi q(n);
	rep(i, n) cin >> q[i], v[i + 1] = 0, ns[i] = -1;
	vi ans(n, -1);
	vector<pi> nd;
	ans[0] = q[0];
	v[q[0]] = 1;
	repn(i, 1, n){
		if(q[i] != q[i - 1]) ans[i] = q[i], v[q[i]] = 1;
		else nd.pb(mp(q[i - 1], i));
	}
	vi pos;
	repn(i, 1, n + 1) if(!v[i]) pos.pb(i);
	sort(all(nd), cmp);
	reverse(all(pos));
	int ind = (int)pos.size() - 1;
	rep(i, nd.size()){
		if(ind < 0){	
			cout << "-1" << endl;
			return;
		}
		while(ind && pos[ind] >= nd[i].fi) ind--;
		ns[nd[i].se] = pos[ind];
		if(!ind && pos[ind] >= nd[i].fi){
			cout << "-1" << endl;
			return;
		}
		ind--;
	}
	rep(i, n) if(ans[i] == -1 && ns[i] == -1){
		cout << "-1" << endl;
		return;
	}
	rep(i, n){
		if(ans[i] == -1) ans[i] = ns[i];
		cout << ans[i] << " ";
	}
	cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
