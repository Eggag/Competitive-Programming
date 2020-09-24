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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, m, k, s;
ll p[mxN], q[mxN];

bool check(ll g){
	ll l = 0;
	rep(i, n){
		//go left
		if(l >= m) return 1;
		ll mx = -1;
		ll l1 = l, r1 = m - 1;	
		while(l1 < r1){
			ll mid1 = (l1 + r1 + 1) / 2;
			if(q[mid1] < p[i]) l1 = mid1;
			else r1 = mid1 - 1;
		}
		if(q[l] < p[i]){
			ll nm = l1 - l + 1;
			ll tk = nm * s + (p[i] - q[l]);
			if(tk > g) return 0;
			ll l4 = l1;
			ll l3 = l1, r3 = m - 1;	
			while(l3 < r3){
				ll mid3 = (l3 + r3 + 1) / 2;
				if((tk + s * max(0LL, mid3 - l4) + ((mid3 > l4) ? q[mid3] - q[l] : 0)) <= g) l3 = mid3;
				else r3 = mid3 - 1;
			}
			if((tk + s * max(0LL, l3 - l4) + ((l3 > l4) ? q[l3] - q[l] : 0)) > g){
				return 0;
			}
			mx = l3;
		}
		//go right
		ll l2 = l1 + (q[l1] < p[i]), r2 = m - 1;
		int f = 0;
		while(l2 < r2){
			ll mid2 = (l2 + r2 + 1) / 2;
			if(((s * (mid2 - l + 1)) + (q[mid2] - p[i]) + (q[l] > p[i] ? 0 : q[mid2] - q[l])) <= g) l2 = mid2, f = 1;
			else r2 = mid2 - 1;
		}
		if((s * (l2 - l + 1) + (q[l2] - p[i]) + (q[l] > p[i] ? 0 : q[l2] - q[l])) <= g) f = 1;
		if(f) mx = max(mx, l2);
		if(mx != -1){
			l = mx + 1;
		}
	}
	if(l >= m) return 1;
	else return 0;
}

ll solve(){
	cin >> n >> m >> k >> s;
	rep(i, k) cin >> p[i];
	ll ap, bp, cp, dp;
	cin >> ap >> bp >> cp >> dp;
	rep(i, k) cin >> q[i];
	ll aq, bq, cq, dq;
	cin >> aq >> bq >> cq >> dq;
	repn(i, k, n) p[i] = ((ap * p[i - 2] + bp * p[i - 1] + cp) % dp) + 1;
	repn(i, k, m) q[i] = ((aq * q[i - 2] + bq * q[i - 1] + cq) % dq) + 1;
	sort(p, p + n);
	sort(q, q + m);
	ll l = 0LL, r = 1e18;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
