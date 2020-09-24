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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	ll tot2 = 0, tot1 = 0;
	vector<pair<ll, pi>> p;
	vector<ll> t(n), a(n), b(n);
	rep(i, n){
		cin >> t[i] >> a[i] >> b[i], tot2 += a[i], tot1 += b[i];
		p.pb(mp(t[i], mp(a[i], b[i])));
	}
	if(tot2 < k || tot1 < k){
		cout << -1 << endl;
		return 0;
	}
	sort(all(p));
	ll ans = 1e18;
	ll cnt = 0, cnt1 = 0;	
	ll tot = 0LL;
	vector<ll> mn(n + 2, 1e9), mn1(n + 2, 1e9);
	mn[0] = 0, mn1[0] = 0;
	int ind = 0, ind1 = 0;
	rep(i, n){
		if(p[i].se.fi && !p[i].se.se){
			mn[ind + 1] = mn[ind] + p[i].fi;
			ind++;
		}
		else if(!p[i].se.fi && p[i].se.se){
			mn1[ind1 + 1] = mn1[ind1] + p[i].fi;
			ind1++;
		}
	}
	rep(i, n){
		if(cnt >= k && cnt1 >= k) break;
		if(p[i].se.se && p[i].se.fi){
			if(ind >= k - cnt && ind1 >= k - cnt1) ans = min(ans, tot + mn[k - cnt] + mn1[k - cnt1]);
			cnt++, cnt1++;
			tot += p[i].fi;
			if(ind >= k - cnt && ind1 >= k - cnt1) ans = min(ans, tot + mn[k - cnt] + mn1[k - cnt1]);
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
