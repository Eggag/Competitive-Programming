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

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	int f = 1;
	if(abs(a - b) > (x2 - x1)) f = 0;
	if(b >= a && (x2 - x) < (b - a)) f = 0;
	else if((x - x1) < (a - b)) f = 0;
	if(abs(d - c) > (y2 - y1)) f = 0;
	if(d >= c && (y2 - y) < (d - c)) f = 0;
	else if((y - y1) < (c - d)) f = 0;
	if(a == b && x1 == x2 && a) f = 0;
	if(c == d && y1 == y2 && c) f = 0;
	if(!f) cout << "No" << endl;
	else cout << "Yes" << endl;
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
