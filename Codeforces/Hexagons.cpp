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

ll x, y;
ll c[6];

void solve1(){
	ll ret = 4e18;
	ret = min(ret, c[2 - 1] * x + c[6 - 1] * y);
	if(x >= y){
		ret = min(ret, c[2 - 1] * (x - y) + c[1 - 1] * y);
		ret = min(ret, c[3 - 1] * (x - y) + c[1 - 1] * x);
	}
	else{
		ret = min(ret, c[6 - 1] * (y - x) + c[1 - 1] * x);
		ret = min(ret, c[5 - 1] * (y - x) + c[1 - 1] * y);
	}
	cout << ret << endl;
}

void solve2(){
	ll ret = 4e18;
	ret = min(ret, c[5 - 1] * x + c[6 - 1] * y);
	ret = min(ret, c[5 - 1] * (x + y) + c[1 - 1] * y);
	ret = min(ret, c[6 - 1] * (x + y) + c[4 - 1] * x);
	cout << ret << endl;
}

void solve(){
	cin >> x >> y;
	rep(i, 6) cin >> c[i];
	swap(x, y);
	if(x >= 0 && y >= 0) solve1();
	else if(x <= 0 && y <= 0){
		x *= -1, y *= -1;
		swap(c[6 - 1], c[3 - 1]), swap(c[5 - 1], c[2 - 1]), swap(c[1 - 1], c[4 - 1]);
		solve1();
	}
	else if(x <= 0 && y >= 0) x *= -1, solve2();
	else{
		y *= -1;
		swap(c[6 - 1], c[3 - 1]), swap(c[5 - 1], c[2 - 1]), swap(c[1 - 1], c[4 - 1]);
		solve2();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
