#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
	int n, s;
	cin >> n >> s;
	vi a(n);
	vector<pi> b(n);
	rep(i, n){
		int x, y;
		cin >> x >> y;
		b[i] = mp(x, y);
		a[i] = x * 60 + y;
	}
	if(a[0] > s){
		cout << "0 0" << endl;
		return 0;
	}
	repn(i, 1, n){
		if((a[i] - a[i - 1]) > (2 * s + 1)){
			int ans = (a[i - 1] + s + 1);
			int ans1 = (a[i - 1] + s + 1) / 60;
			int ans2 = ans % 60;
			cout << ans1 << " " << ans2 << endl;
			return 0;
		}
	}
	b[n - 1].se += s + 1;
	if(b[n - 1].se >= 60) b[n - 1].fi++;
	if(b[n - 1].se >= 120) b[n - 1].fi++;
	cout << b[n - 1].fi << " " << b[n - 1].se % 60 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
