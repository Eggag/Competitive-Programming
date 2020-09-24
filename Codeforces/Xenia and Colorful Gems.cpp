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

void solve(){
	int r, g, b;
	cin >> r >> g >> b;
	vector<ll> R(r), G(g), B(b);
	rep(i, r) cin >> R[i];
	rep(i, g) cin >> G[i];
	rep(i, b) cin >> B[i];
	sort(all(R));
	sort(all(G));
	sort(all(B));
	ll ans = 2e18;
	rep(i, r){
		vector<ll> G1, B1;
		int cl = lb(all(G), R[i]) - G.begin();
		if(cl < (int)G.size()) G1.pb(G[cl]);
		if(cl > 0) G1.pb(G[cl - 1]);
		int cl1 = lb(all(B), R[i]) - B.begin();
		if(cl1 < (int)B.size()) B1.pb(B[cl1]);
		if(cl1 > 0) B1.pb(B[cl1 - 1]);
		rep(j, G1.size()){
			int cl2 = lb(all(B), G1[j]) - B.begin();
			if(cl2 < (int)B.size()) B1.pb(B[cl2]);
			if(cl2 > 0) B1.pb(B[cl2 - 1]);
		}
		rep(j, B1.size()){
			int cl2 = lb(all(G), B1[j]) - G.begin();
			if(cl2 < (int)G.size()) G1.pb(G[cl2]);
			if(cl2 > 0) G1.pb(G[cl2 - 1]);
		}
		rep(j, G1.size()) rep(k, B1.size()){
			ans = min(ans, sq(R[i] - G1[j]) + sq(R[i] - B1[k]) + sq(G1[j] - B1[k]));
		}
	}
	rep(i, g){
		vector<ll> R1, B1;
		int cl = lb(all(R), G[i]) - R.begin();
		if(cl < (int)R.size()) R1.pb(R[cl]);
		if(cl > 0) R1.pb(R[cl - 1]);
		int cl1 = lb(all(B), G[i]) - B.begin();
		if(cl1 < (int)B.size()) B1.pb(B[cl1]);
		if(cl1 > 0) B1.pb(B[cl1 - 1]);
		rep(j, R1.size()){
			int cl2 = lb(all(B), R1[j]) - B.begin();
			if(cl2 < (int)B.size()) B1.pb(B[cl2]);
			if(cl2 > 0) B1.pb(B[cl2 - 1]);
		}
		rep(j, B1.size()){
			int cl2 = lb(all(R), B1[j]) - R.begin();
			if(cl2 < (int)R.size()) R1.pb(R[cl2]);
			if(cl2 > 0) R1.pb(R[cl2 - 1]);
		}
		rep(j, R1.size()) rep(k, B1.size()){
			ans = min(ans, sq(G[i] - R1[j]) + sq(G[i] - B1[k]) + sq(R1[j] - B1[k]));
		}
	}
	rep(i, b){
		vector<ll> R1, G1;
		int cl = lb(all(G), B[i]) - G.begin();
		if(cl < (int)G.size()) G1.pb(G[cl]);
		if(cl > 0) G1.pb(G[cl - 1]);
		int cl1 = lb(all(R), B[i]) - R.begin();
		if(cl1 < (int)R.size()) R1.pb(R[cl1]);
		if(cl1 > 0) R1.pb(R[cl1 - 1]);
		rep(j, G1.size()){
			int cl2 = lb(all(R), G1[j]) - R.begin();
			if(cl2 < (int)R.size()) R1.pb(R[cl2]);
			if(cl2 > 0) R1.pb(R[cl2 - 1]);
		}
		rep(j, R1.size()){
			int cl2 = lb(all(G), R1[j]) - G.begin();
			if(cl2 < (int)G.size()) G1.pb(G[cl2]);
			if(cl2 > 0) G1.pb(G[cl2 - 1]);
		}
		rep(j, G1.size()) rep(k, R1.size()){
			ans = min(ans, sq(B[i] - G1[j]) + sq(B[i] - R1[k]) + sq(G1[j] - R1[k]));
		}
	}
	cout << ans << endl;
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
