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

bool intersect(pi a, pi b){
	if(a.fi >= b.fi && a.fi <= b.se) return 1;
	if(a.se >= b.fi && a.se <= b.se) return 1;
	if(b.fi >= a.fi && b.fi <= a.se) return 1;
	if(b.se >= a.fi && b.se <= a.se) return 1;
	return 0;
}

void solve(){
	int n, x, m;
	cin >> n >> x >> m;
	vector<pi> p(m);
	rep(i, m) cin >> p[i].fi >> p[i].se;
	int st = -1;
	rep(i, m) if(x >= p[i].fi && x <= p[i].se){
		st = i;
		break;
	}
	if(st == -1){
		cout << 1 << endl;
		return;
	}
	queue<int> q;
	vi vis(m, 0);
	vis[st] = 1;
	int mn = p[st].fi, mx = p[st].se;
	q.push(st);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		repn(i, cur + 1, m) if(!vis[i] && intersect(p[cur], p[i])){
			q.push(i);
			vis[i] = 1;
			mn = min(mn, p[i].fi);
			mx = max(mx, p[i].se);
		}
	}
	cout << mx - mn + 1 << endl;
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
