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

vi g[500005];
int t[500005];
int gd[500005];

bool cmp(int a, int b){
	return t[a - 1] < t[b - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	map<int, vi> col;
	rep(i, n) cin >> t[i], col[t[i]].pb(i);
	rep(i, n){
		for(int u : g[i]){
			if(t[i] == t[u]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	vi a;
	repn(i, 1, n + 1) a.pb(i);
	sort(all(a), cmp);
	vi cur = a;
	for(pair<int, vi> x : col){
		memset(gd, 0, sizeof(gd));
		rep(i, x.se.size()){
			if(x.fi == 1) gd[x.se[i]] = 1;
			for(int u : g[x.se[i]]){
				gd[u] = 1;
			}
		}
		vi cur1;
		rep(i, cur.size()){
			if(!gd[cur[i] - 1]){
				if(x.fi < t[cur[i] - 1]){
					cout << -1 << endl;
					return 0;
				}
			}
			else cur1.pb(cur[i]);
		}
		swap(cur, cur1);
	}
	for(int x : a) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
