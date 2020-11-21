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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi r[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int nm;
		cin >> nm;
		rep(j, nm){
			int x;
			cin >> x;
			x--;
			r[i].pb(x);
		}
		reverse(all(r[i]));
	}
	vector<pi> ans;
	repn(i, 1, m){
		while(r[i].size()){
			ans.pb({i, 0});
			r[0].pb(r[i][(int)r[i].size() - 1]);
			r[i].pop_back();
		}
	}
	while(r[0].size()){
		int i = (int)(r[0].size()) - 1;
		if(r[0][i] > 1){
			ans.pb({0, r[0][i]});
			r[r[0][i]].pb(r[0][i]);
		}
		else{
			ans.pb({0, 1});
			r[1].pb(r[0][i]);
		}
		r[0].pop_back();
	}
	while(r[1].size()){
		int i = (int)(r[1].size()) - 1;
		if(r[1][i] == 0) ans.pb({1, 0});
		else{
			ans.pb({1, 2});
			r[2].pb(1);
		}
		r[1].pop_back();
	}
	while(r[2].size()){
		int i = (int)(r[2].size()) - 1;
		if(r[2][i] == 1) ans.pb({2, 1});
		else break;
		r[2].pop_back();
	}
	cout << (int)(ans.size()) << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
