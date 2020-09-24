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
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	if(k == 2){
		map<vi, ll> m;
		rep(i, n){
			vi f(100005, 0);
			for(int j = 2; (j * j) <= a[i]; j++){
				while(a[i] % j == 0){
					a[i] /= j;
					f[j]++;
				}
			}
			vi cur;
			rep(j, 1005) if(f[j] & 1) cur.pb(j);
			if(a[i] > 1){
				f[a[i]]++;
				if(f[a[i]] & 1) cur.pb(a[i]);
			}
			m[cur]++;
		}
		ll ans = 0;
		for(pair<vi, ll> x : m) ans += x.se * (x.se - 1);
		cout << ans / 2 << endl;
	}
	else{
		vector<ll> pos;
		for(ll i = 1; i <= 10005; i++){
			ll num = i;
			int f = 1;
			rep(j, k - 1){
				num *= i;
				if(num > 1e10){
					f = 0;
					break;
				}
			}
			if(!f) break;
			else pos.pb(num);
		}
		map<int, ll> b;
		rep(i, n) b[a[i]]++;
		ll ans = 0;
		rep(i, pos.size()){
			for(ll j = 1; (j * j) <= pos[i]; j++){
				if(pos[i] % j == 0){
					if(j == (pos[i] / j)) ans += (b[j] * (b[j] - 1)) / 2;	
					else ans += (b[j] * b[pos[i] / j]);
				}
			}
		}
		cout << ans << endl;
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
