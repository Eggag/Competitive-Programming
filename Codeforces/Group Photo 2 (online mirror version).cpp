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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	ll ans = 1e18;
	rep(i, n){
		ll h = p[i].fi, tot = p[i].se;
		int num = (n / 2) - 1;
		int f = 1;
		vi vis(n, 0);
		vis[i] = 1;
		rep(j, n) if(j != i){
			if(p[j].se > h){
				if(p[j].fi > h){
					f = 0;
					break;
				}
				else if(num){
					tot += p[j].se;
					vis[j] = 1;
					num--;
				}
				else{
					f = 0;
					break;
				}
			}
		}
		vector<pair<ll, int>> pos;
		rep(j, n) if(!vis[j]){
			if(p[j].se < p[j].fi && p[j].fi <= h){
				pos.pb(mp(p[j].fi - p[j].se, j));
			}
			else tot += p[j].fi, vis[j] = 1;
		}
		sort(all(pos));
		reverse(all(pos));
		rep(j, pos.size()){
			if(num){
				tot += p[pos[j].se].se;
				num--;
			}
			else tot += p[pos[j].se].fi;
		}
		if(f) ans = min(ans, h * tot);
	}
	rep(i, n){
		ll h = p[i].se, tot = p[i].fi;
		int num = n / 2;
		int f = 1;
		vi vis(n, 0);
		vis[i] = 1;
		rep(j, n) if(j != i){
			if(p[j].se > h){
				if(p[j].fi > h){
					f = 0;
					break;
				}
				else if(num){
					tot += p[j].se;
					vis[j] = 1;
					num--;
				}
				else{
					f = 0;
					break;
				}
			}
		}
		vector<pair<ll, int>> pos;
		rep(j, n) if(!vis[j]){
			if(p[j].se < p[j].fi && p[j].fi <= h){
				pos.pb(mp(p[j].fi - p[j].se, j));
			}
			else tot += p[j].fi, vis[j] = 1;
		}
		sort(all(pos));
		reverse(all(pos));
		rep(j, pos.size()){
			if(num){
				tot += p[pos[j].se].se;
				num--;
			}
			else tot += p[pos[j].se].fi;
		}
		if(f) ans = min(ans, h * tot);
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
