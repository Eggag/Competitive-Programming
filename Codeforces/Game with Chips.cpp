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
	int n, m, k;
	cin >> n >> m >> k;
	vector<pi> p(k), p1(k);
	rep(i, k) cin >> p[i].fi >> p[i].se;
	rep(i, k) cin >> p1[i].fi >> p1[i].se;
	string ans = "";
	rep(i, m - 1) ans += 'L';
	rep(i, n - 1) ans += 'U';
	rep(i, m){
		rep(j, n - 1){
			if(i & 1) ans += 'U';
			else ans += 'D';
		}
		if(i != (m - 1)) ans += 'R';
	}
	if((int)ans.size() > (2 * n * m)){
		cout << -1 << endl;
	}
	else{
		cout << ans.size() << endl;
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/