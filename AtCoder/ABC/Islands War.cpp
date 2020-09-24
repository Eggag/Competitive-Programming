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

vi st[100005], en[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> a(m);
	vector<pair<int, pi>> p;
	rep(i, m){
		cin >> a[i].fi >> a[i].se;
		p.pb(mp(a[i].fi, mp(i, 1)));
		p.pb(mp(a[i].se, mp(i, 0)));
		st[a[i].fi].pb(i);
		en[a[i].se].pb(i);
	}
	int ans = 0;
	int need = 1; //need to find a new base segment
	int mn = 1e9;
	sort(all(p)); //all endpoints
	rep(i, 2 * m){
		if(mn == p[i].fi && !need){
			ans++;
			need = 1;
		}
		if(need){
			if(p[i].se.se){
				need = 0;
				mn = a[p[i].se.fi].se; //found that segment
			}
		}
		else{
			if(p[i].se.se){
				mn = min(mn, a[p[i].se.fi].se);
			}
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
