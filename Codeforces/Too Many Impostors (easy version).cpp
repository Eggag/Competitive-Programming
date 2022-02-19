#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

int ask(int a, int b, int c){
	a++, b++, c++;
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	array<int, 3> a = {-1, -1, -1};
	array<int, 3> b = {-1, -1, -1};
	for(int i = 0; i < n; i += 3){
		int nw = ask(i, i + 1, i + 2);
		if(nw && a[0] == -1) a = {i, i + 1, i + 2};
		if(!nw && b[0] == -1) b = {i, i + 1, i + 2};
	}
	int cr = -1, imp = -1;
	int cnt = 0;
	rep(k, 3){
		int nw = ask(a[0], a[1], b[k]);
		cnt += 1 - nw;
		if(!nw) imp = b[k], cr = a[2];
	}
	if(!cnt) cr = a[0];
	int cnt1 = 0;
	rep(k, 3){
		int nw = ask(b[0], b[1], a[k]);
		cnt1 += nw;
		if(nw) imp = b[2];
	}
	if(!cnt1) imp = b[0];
	assert(imp != -1 && cr != -1);
	vi ans = {imp};
	rep(i, n) if(i != imp && i != cr){
		int uwu = ask(imp, cr, i);
		if(!uwu) ans.pb(i);
	}
	cout << "! " << (int)(ans.size()) << ' ';
	for(int x : ans) cout << x + 1 << ' ';
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
