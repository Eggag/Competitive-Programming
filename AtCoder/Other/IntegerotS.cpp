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
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	int hk = 0; //highest bit in k
	for(int j = 31; j >= 0; j--){
		if(k & (1LL << j)){
			hk = j;
			break;
		}
	}
	ll ans = 0;
	rep(i, n){
		int h = 0; //highest bit
		for(int j = 31; j >= 0; j--){
			if((p[i].fi & (1LL << j))){
				h = j;
				break;
			}
		}
		if(h < hk) ans += p[i].se;
	}
	//debug(ans);
	repn(bit, 0, 32) if(bit <= hk && (k & (1LL << (hk - bit)))){
		ll ans1 = 0;
		rep(j, n){
			int f = 1, g = 0;
			for(int m = 31; m >= 0; m--){
				if((p[j].fi & (1LL << m))){
					if(!(k & (1LL << m)) && !g){
						f = 0;
						break;
					}
				}
				else if(k & (1LL << m)) g = 1;
			}
			if(!f) continue;
			for(int m = 31; m >= 0; m--) if((p[j].fi & (1LL << m))){
				if((m > (hk - bit) && !(k & (1LL << m))) || (m == (hk - bit))){
					f = 0;
					break;
				}
			}
			if(!f) continue;
			ans1 += p[j].se;
		}
		//debug(ans1);
		ans = max(ans, ans1);
	}
	ll ans2 = 0;
	rep(j, n){
		int f = 1;
		for(int m = 31; m >= 0; m--) if((p[j].fi & (1LL << m))){
			if(m > hk || (m <= hk && !(k & (1LL << m)))){
				f = 0;
				break;
			}
		}
		if(f) ans2 += p[j].se;
	}
	ans = max(ans, ans2);
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
