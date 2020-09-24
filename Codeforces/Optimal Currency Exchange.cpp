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
	int n, d, e;
	cin >> n >> d >> e;
	int ans = n;
	rep(i, 3333339){
		//i is the number of dollar bills
		int cur = i * d;
		if(cur > n) continue;
		int div = (n - cur) / e;
		int sum = e * div;
		if(div % 5 != 0) continue;
		cur += sum;
		if(cur > n) continue;
		ans = min(ans, n - cur);
	}
	rep(i, 3333339){
		int cur = i * d;
		if(cur <= n) ans = min(ans, n - cur);
	}
	rep(i, 3333339) if(i % 5 == 0){
		int cur = i * e;
		if(cur <= n) ans = min(ans, n - cur);
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
