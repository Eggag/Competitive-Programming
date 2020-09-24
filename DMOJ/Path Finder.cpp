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
const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct HASH{
	size_t operator () (const pi &x) const{
		return hash<ll>()(((ll)(x.first)) ^ (((ll)(x.second)) << 32));
	}
};

unordered_map<pi, int, HASH> vis;
unordered_map<pi, int, HASH> gd;

int n, m, k;

bool valid(int x, int y){
	return (x >= 1 && y >= 1 && x <= n && y <= m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	vi r(k), c(k);
	rep(i, k) cin >> r[i] >> c[i], gd[mp(r[i], c[i])] = 1;
	queue<pi> q;
	rep(i, k) if(c[i] == 1) vis[mp(r[i], c[i])] = 1, q.push(mp(r[i], c[i]));
	while(!q.empty()){
		pi cur = q.front();	
		q.pop();
		rep(i, 8){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && gd[mp(x, y)] && !vis[mp(x, y)]){
				vis[mp(x, y)] = 1;
				q.push(mp(x, y));
			}
		}
	}
	rep(i, k){
		if((r[i] == 1 || c[i] == m) && (vis[mp(r[i], c[i])])){
			cout << "NO" << endl;
			return 0;
		}
	}
	vis.clear();
	rep(i, k) if(r[i] == n) vis[mp(r[i], c[i])] = 1, q.push(mp(r[i], c[i]));
	while(!q.empty()){
		pi cur = q.front();	
		q.pop();
		rep(i, 8){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && gd[mp(x, y)] && !vis[mp(x, y)]){
				vis[mp(x, y)] = 1;
				q.push(mp(x, y));
			}
		}
	}
	rep(i, k){
		if((r[i] == 1 || c[i] == m) && (vis[mp(r[i], c[i])])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
