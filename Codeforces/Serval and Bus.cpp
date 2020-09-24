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
	int n;
	ll t;
	cin >> n >> t;
	vector<ll> s(n), d(n);
	ll ans = 1e18;
	int best = -1;
	rep(i, n){
		cin >> s[i] >> d[i];
		ll l = 0, r = 1000000;
		while(l < r){
			ll mid = (l + r) / 2;
			if(t <= (s[i] + (mid * d[i]))) r = mid;
			else l = mid + 1;
		}
		if((s[i] + (l * d[i])) <= ans) best = i + 1, ans = (s[i] + (l * d[i]));
	}
	cout << best << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
