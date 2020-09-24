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

void solve(){
	int r, g, b, w;
	cin >> r >> g >> b >> w;
	repn(i, 0, 3) if(min({r, g, b}) >= i){
		int r1 = r - i, g1  = g - i, b1 = b - i, w1 = w + i;	
		int tot = 0;
		if(r1) tot++;
		if(g1) tot++;
		if(b1) tot++;
		if(w1) tot++;
		int odd = 0;
		if(r1 & 1) odd++;
		if(g1 & 1) odd++;
		if(b1 & 1) odd++;
		if(w1 & 1) odd++;
		if(odd <= 1){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
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
