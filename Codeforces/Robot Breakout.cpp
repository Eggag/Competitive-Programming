#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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
const int inf = 1e5;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	int llim = -inf;
	int ulim = inf;
	int dlim = -inf;
	int rlim = inf;
	rep(i, n){
		int x, y, f1, f2, f3, f4;
		cin >> x >> y >> f1 >> f2 >> f3 >> f4;
		if(!f1) llim = max(llim, x);
		if(!f2) ulim = min(ulim, y);
		if(!f3) rlim = min(rlim, x);
		if(!f4) dlim = max(dlim, y);
	}
	if((llim <= rlim) && (ulim >= dlim)){
		cout << 1 << " " << llim << " " << ulim << endl;
	}
	else{
		cout << 0 << endl;
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
