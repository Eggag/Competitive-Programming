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
	int n, m;
	cin >> n >> m;
	ll x, k, y;
	cin >> x >> k >> y;
	swap(x, y);
	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vi rem(n, 0);
	map<int, int> cnt;
	rep(i, m) cnt[b[i]]++;
	int ind = 0;
	rep(i, n){
		if(!cnt[a[i]]) rem[i] = 1;
		else{
			if(a[i] != b[ind]){
				cout << -1 << endl;
				return 0;
			}
			ind++;
		}
	}
	if(ind != m){
		cout << -1 << endl;
		return 0;
	}
	vector<pi> segs;
	int l = -1;
	rep(i, n){
		if(l == -1 && rem[i]) l = i;
		else if(l != -1 && !rem[i]){
			segs.pb({l, i - 1});
			l = -1;
		}
	}
	if(l != -1) segs.pb({l, n - 1});
	ll cost = 0LL;
	rep(i, segs.size()){
		//we check for the border max
		int l1 = segs[i].fi, r1 = segs[i].se;
		ll mx = 0LL;
		if(l1 > 0) mx = max(mx, a[l1 - 1]);
		if(r1 < (n - 1)) mx = max(mx, a[r1 + 1]);
		vi bad;
		repn(j, l1, r1 + 1) if(a[j] > mx) bad.pb(j);
		if((r1 - l1 + 1) < k){
			if(bad.size()){
				cout << -1 << endl;
				return 0;
			}
			else cost += (x * (r1 - l1 + 1));
			continue;
		}
		assert((r1 - l1 + 1) >= k);
		if(y <= (x * k)){
			//we fill in as many as we can with k's
			ll num = (r1 - l1 + 1) / k;
			cost += (x * ((r1 - l1 + 1) % k)) + (num * y);
		}
		else{
			if(bad.size()) cost += (x * ((r1 - l1 + 1) - k)) + y;
			else cost += x * (r1 - l1 + 1);
		}
	}
	cout << cost << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
