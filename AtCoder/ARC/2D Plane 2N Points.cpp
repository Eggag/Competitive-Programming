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

vi pos[105];
vi pos1[105];

bool cmp(pair<pi, int> a, pair<pi, int> b){
	return (int)(pos[a.se].size()) < (int)(pos[b.se].size());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<pi, int>> a(n), b(n);
	rep(i, n) cin >> a[i].fi.fi >> a[i].fi.se, a[i].se = i;
	rep(i, n) cin >> b[i].fi.fi >> b[i].fi.se, b[i].se = i;
	int ans = 0;
	rep(i, n) rep(j, n) if(a[i].fi.fi < b[j].fi.fi && a[i].fi.se < b[j].fi.se){
		pos[i].pb(j);
		pos1[j].pb(i);
	}
	sort(all(a), cmp);
	vi vis(n, 0);
	rep(i, n){
		int cur = -1;
		int mn = 1e9;
		rep(j, pos[a[i].se].size()) if(!vis[pos[a[i].se][j]]){
			int nw = pos1[pos[a[i].se][j]].size();
			if(nw < mn) cur = pos[a[i].se][j], mn = nw;
		}
		if(cur != -1){
			rep(j, pos[a[i].se].size()){
				rep(k, pos1[pos[a[i].se][j]].size()){
					if(pos1[pos[a[i].se][j]][k] == a[i].se){
						pos1[pos[a[i].se][j]].erase(pos1[pos[a[i].se][j]].begin() + k);
						break;
					}
				}
			}
			vis[cur] = 1;
			ans++;
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

