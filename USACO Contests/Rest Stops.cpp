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

bool cmp(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b){
	return a.fi.se > b.fi.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	ll l, n, rf, rb;
	cin >> l >> n >> rf >> rb;
	vector<pair<pair<ll, ll>, int>> st(n + 1, mp(mp(0LL, 0LL), 0));
	repn(i, 1, n + 1) cin >> st[i].fi.fi >> st[i].fi.se, st[i].se = i;
	vector<ll> tm(n + 1);
	tm[0] = 0;
	repn(i, 1, n + 1) tm[i] = tm[i - 1] + ((st[i].fi.fi - st[i - 1].fi.fi) * (rf - rb));
	sort(st.begin() + 1, st.end(), cmp);
	//we always prioritize going to the ones with higher c
	//if it is after, then go to it without stopping, if it is before -
	//stay there as long as you can and only when FJ reaches you, go to the next one
	//also, prefix sums on time can be useful
	int prev = 0; //the index of the last on we have been at
	ll ans = 0;
	repn(i, 1, n + 1) if(st[i].se > prev){
		ans += (tm[st[i].se] - tm[prev]) * (st[i].fi.se);
		prev = st[i].se;
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
