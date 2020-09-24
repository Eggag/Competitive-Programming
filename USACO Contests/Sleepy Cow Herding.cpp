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
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	vi c(3);
	rep(i, 3) cin >> c[i];
	sort(all(c));
	int mn = 2;
	if(c[1] == (c[0] + 1) && c[2] == (c[1] + 1)) mn = min(mn, 0);
	else if(c[1] == (c[0] + 1) || c[2] == (c[1] + 1)) mn = 2;
	else if(c[1] == (c[0] + 2) || c[2] == (c[1] + 2)) mn = min(mn, 1);
	int mx = max({(c[1] - c[0] - 1), (c[2] - c[1] - 1)});
	cout << mn << endl << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
