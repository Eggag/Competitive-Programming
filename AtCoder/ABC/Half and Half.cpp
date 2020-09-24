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
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if((c * 2) < (a + b)){
		//cheaper to buy AB's
		ans = min(x, y) * (c * 2);
		int mn = min(x, y);
		x -= mn;
		y -= mn;
	}
	else{
		ans = min(x, y) * (a + b);
		int mn = min(x, y);
		x -= mn;
		y -= mn;
	}
	if(x){
		//we need to buy this many more a's, no more b's
		if((c * 2) < a) ans += c * 2 * x;
		else ans += a * x;
	}
	if(y){
		if((c * 2) < b) ans += c * 2 * y;
		else ans += b * y;
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
