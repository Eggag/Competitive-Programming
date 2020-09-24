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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld n, w;
	cin >> n >> w;
	vector<ld> a(2 * n);
	rep(i, (2 * n)) cin >> a[i];
	sort(all(a));
	ld l = 0, r = 1e10;
	while((r - l) >= 1e-8){
		ld mid = (r + l) / 2;
		if((mid <= a[0]) && (ld)(mid * (ld)2) <= a[n]){
			l = mid;
		}
		else r = mid;
	}
	cout << fixed << setprecision(20) << min((ld)w, (ld)((ld)n * (ld)l * (ld)3)) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
