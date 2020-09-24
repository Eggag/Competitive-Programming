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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

unordered_map<int, ll> mx, vert;

ll solve(){
	ll n, k, w;
	cin >> n >> k >> w;
	mx.clear();
	vert.clear();
	vector<ll> l(n), h(n);
	rep(i, k) cin >> l[i];
	ll aL, bL, cL, dL;
	cin >> aL >> bL >> cL >> dL;
	rep(i, k) cin >> h[i];
	ll aH, bH, cH, dH;
	cin >> aH >> bH >> cH >> dH;
	repn(i, k, n) l[i] = ((aL * l[i - 2] + bL * l[i - 1] + cL) % dL) + 1;
	repn(i, k, n) h[i] = ((aH * h[i - 2] + bH * h[i - 1] + cH) % dH) + 1;
	ll ans = 1LL;
	ll cur = 0LL;
	rep(i, n){
		repn(j, l[i], l[i] + w){
			if(!mx[j]) cur += 2; //up and down
			if(h[i] > mx[j]){
				mx[j] = max(mx[j], h[i]);
				cur -= vert[j];
				vert[j] = abs(mx[j - 1] - mx[j]);
				cur += vert[j];
			}
		}
		int j = l[i] + w;
		cur -= vert[j];
		vert[j] = abs(mx[j - 1] - mx[j]);
		cur += vert[j];
		(ans *= (cur % MOD)) %= MOD;
	}
	return ans;
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
