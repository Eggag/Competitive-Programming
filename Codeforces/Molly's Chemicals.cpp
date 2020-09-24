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
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	vector<ll> cnt(n + 1);
	cnt[0] = 0;
	repn(i, 1, n + 1) cnt[i] = cnt[i - 1] + a[i];
	map<ll, ll> m;
	m[0] = 1;
	ll ans = 0;
	repn(i, 1, n + 1){
		int cnt1 = 0;
		if(k == 1){
			ans += m[cnt[i] - 1];
		}
		else if(k == -1){
			ans += m[cnt[i] - 1];
			ans += m[cnt[i] + 1];
		}
		else{
			for(ll j = 1; abs(j) <= (ll)1e14; j *= k){
				ans += m[cnt[i] - j];
				cnt1++;
				if(cnt1 > 100) break;
			}
		}
		m[cnt[i]]++;
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
