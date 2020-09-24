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
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vi p;
	rep(i, n){
		int cur = a[i] - b[i];
		p.pb(cur);
	}
	sort(all(p));
	reverse(all(p));
	ll ans = 0;
	rep(i, n){
		int cur = a[i] - b[i];
		int l = 0, r = p.size() - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(p[mid] >= (-cur + 1)) l = mid;
			else r = mid - 1;
		}
		int nm = l;
		if((p[nm] + cur) <= 0) nm--;
		if(p[0] <= (-cur)){
			continue;
		}
		ans += nm + 1 - (p[nm] <= cur);
	}
	cout << ans / 2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
