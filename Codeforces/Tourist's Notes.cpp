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
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	ll prevD = 0, prevH = 0;
	rep(i, m){
		ll d, h;
		cin >> d >> h;
		ans = max(h, ans);
		if(i){
			if(abs(h - prevH) > (d - prevD)){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			ans = max(ans, max(h, prevH) + ((d - prevD) - abs(h - prevH)) / 2);
		}
		if(!i) ans = max(ans, h + (d - 1));
		prevD = d, prevH = h;
	}
	cout << max({ans, prevH + (n - prevD), }) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/