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

int n, x, y, x2, y2;
int dist[mxN][2];
vi v[mxN], h[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	cin >> n >> x >> y >> x2 >> y2;
	set<int> st, st1;
	st.insert(x);
	st.insert(x2);
	st1.insert(y);
	st1.insert(y2);
	vector<pi> p(n + 2);
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		st.insert(p[i].fi);
		st1.insert(p[i].se);
	}
	int cnt = 0;
	map<int, int> m, m1;
	for(int nm : st){
		m[nm] = cnt;
		cnt++;
	}
	cnt = 0;
	for(int nm : st1){
		m1[nm] = cnt;
		cnt++;
	}
	x = m[x], y = m1[y], x2 = m[x2], y2 = m1[y2];
	rep(i, n) p[i].fi = m[p[i].fi], p[i].se = m1[p[i].se];
	//now we can get on with the rest of the problem
	//(we compressed so now we can do all the stuff with arrays instead of maps)
	p[n] = mp(x, y);
	p[n + 1] = mp(x2, y2);
	rep(i, n + 2){
		v[p[i].fi].pb(i);
		h[p[i].se].pb(i);
	}
	rep(i, mxN) rep(j, 2) dist[i][j] = 1e9;
	set<pair<int, pi>> q;
	dist[n][0] = 0;
	dist[n][1] = 0;
	q.insert(mp(0, mp(n, 0)));
	q.insert(mp(0, mp(n, 1)));
	while(!q.empty()){
		pair<int, pi> cur = *q.begin();
		q.erase(q.begin());
		if(cur.se.fi == (n + 1)){
			cout << cur.fi - 1 << endl;
			return 0;
		}
		if(cur.se.se){
			//update horizontal
			int y3 = p[cur.se.fi].se;
			rep(i, h[y3].size()) if(h[y3][i] != cur.se.fi){
				int nw = h[y3][i];
				if(dist[nw][0] > (cur.fi + 1)){
					q.erase(mp(dist[nw][0], mp(nw, 0)));
					dist[nw][0] = cur.fi + 1;
					q.insert(mp(dist[nw][0], mp(nw, 0)));
				}
			}
		}
		else{
			//update vertical
			int x3 = p[cur.se.fi].fi;
			rep(i, v[x3].size()) if(v[x3][i] != cur.se.fi){
				int nw = v[x3][i];
				if(dist[nw][1] > (cur.fi + 1)){
					q.erase(mp(dist[nw][1], mp(nw, 1)));
					dist[nw][1] = cur.fi + 1;
					q.insert(mp(dist[nw][1], mp(nw, 1)));
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
