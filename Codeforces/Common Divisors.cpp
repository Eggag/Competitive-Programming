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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	//map<ll, int> cnt;
	ll g = a[0];
	repn(i, 1, n) g = gcd(a[i], g);
	//rep(i, n) a[i] /= g;
	//rep(i, n){
	//	repn(j, 1, sqrt(a[i]) + 1){
	//		if(a[i] % j == 0){
	//			cnt[j]++;
	//			if((a[i] / j) != j) cnt[(a[i] / j)]++;
	//		}
	//	}
	//}
	int ans = 0;
	repn(i, 1, sqrt(g) + 1){
		if(g % i == 0){
			ans++;
			if((g / i) != i) ans++;
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
