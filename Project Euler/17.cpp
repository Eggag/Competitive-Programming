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
	int ans = 0;
	//1 - 9
	ans += 3 * 90;
	ans += 3 * 90;
	ans += 5 * 90;
	ans += 4 * 90;
	ans += 4 * 90;
	ans += 3 * 90;
	ans += 5 * 90;
	ans += 5 * 90;
	ans += 4 * 90;
	//10 - 19
	ans += 3 * 10;
	ans += 6 * 10;
	ans += 6 * 10;
	ans += 8 * 10;
	ans += 8 * 10;
	ans += 7 * 10;
	ans += 7 * 10;
	ans += 9 * 10;
	ans += 8 * 10;
	ans += 8 * 10;
	//20, 30..., 90	
	ans += 6 * 10 * 10;
	ans += 6 * 10 * 10;
	ans += 5 * 10 * 10;
	ans += 5 * 10 * 10;
	ans += 5 * 10 * 10;
	ans += 7 * 10 * 10;
	ans += 6 * 10 * 10;
	ans += 6 * 10 * 10;
	//100, 200, 300..., 900
	ans += 10 * 100;
	ans += 10 * 100;
	ans += 12 * 100;
	ans += 11 * 100;
	ans += 11 * 100;
	ans += 10 * 100;
	ans += 12 * 100;
	ans += 12 * 100;
	ans += 11 * 100;
	//1000
	ans += 11;
	//and
	ans += 3 * (99 * 9);
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
