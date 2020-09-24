#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, b;
	cin >> n >> b;
	vi a(n);
	rep(i, n) cin >> a[i];
	int odd = 0, even = 0;
	vi pos;
	if(a[0] & 1) odd++;
	else even++;
	repn(i, 1, n - 1){
		if(a[i] & 1) odd++;
		else even++;
		if(even == odd) pos.pb(abs(a[i] - a[i + 1]));
	}
	sort(all(pos));
	int ans = 0;
	rep(i, pos.size()){
		if(b >= pos[i]) ans++, b -= pos[i];
		if(b == 0) break;
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
