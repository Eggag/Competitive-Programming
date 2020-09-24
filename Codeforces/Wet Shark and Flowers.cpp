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
	int n, p;
	cin >> n >> p;
	//for each find the ratio (divisible by p) / (r - l + 1)
	//we multiply a thousand by this ration for each and take care of double counting
	vector<ld> l(n), r(n);
	vector<ld> ratio(n);
	cout << fixed << setprecision(15);
	rep(i, n){
		cin >> l[i] >> r[i];
		int ri1 = r[i] / p;
		ld ri = ri1;
		int le1 = (l[i] - 1) / p;
		ld le = le1;
		ratio[i] = (ld)((ri - le) / (r[i] - l[i] + 1));
	}
	ld ans = 0;
	for(int i = 0; i < n; i++){
		int j = (i + 1) % n;
		ans += ratio[i] * 2000;
		ans += ratio[j] * 2000;
		ans -= (ld)(ratio[i] * ratio[j]) * 2000;
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
