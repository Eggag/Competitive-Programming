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
	int d, g;
	cin >> d >> g;
	vi p(d), c(d);
	rep(i, d) cin >> p[i] >> c[i];
	//we can do a bitmask on d
	//do we fill up this guy to get the bonus or not
	//then, we keep adding the most expensive problems
	int ans = 1e9;
	rep(i, (1 << d)){
		ll tot = 0;
		int cnt = 0;
		rep(j, d) if(i & (1 << j)){
			tot += (c[j] + (p[j] * ((j + 1) * 100)));
			cnt += p[j];
		}
		if(tot >= g) ans = min(ans, cnt);
		for(int j = d - 1; j >= 0; j--) if(!(i & (1 << j))){
			if(tot > g) break;
			int pos = p[j];
			while(tot < g && pos){
				tot += (j + 1) * 100;
				cnt++;
				pos--;
			}
		}
		if(tot >= g) ans = min(ans, cnt);
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
