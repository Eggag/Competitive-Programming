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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(int a, int b){
	return (a % 10) > (b % 10);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	int ans = 0;
	rep(i, n) cin >> a[i], ans += a[i] / 10;
	sort(all(a), cmp);
	rep(i, n) if(a[i] < 100){
		int rem = 10 - (a[i] % 10);
		if(rem <= k){
			k -= rem;
			ans++;
			a[i] += rem;
		}
	}
	rep(i, n){
		int nm = 100 - a[i];
		if(k >= nm) ans += nm / 10, k -= nm;
		else{
			ans += k / 10;
			k = 0;
			break;
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
