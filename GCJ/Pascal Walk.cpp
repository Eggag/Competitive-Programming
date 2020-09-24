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

void solve(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << 1 << " " << 1 << endl;
		return;
	}
	vector<pi> ans;
	ll num = 0;
	while((1LL << num) <= n) num++;
	if((n - num) % 2 == 0) num--;
	n -= num;
	int l = 0;
	int st = 35;
	rep(i, 35){
		if((1LL << i) > n){
			st = i;
			break;
		}
		if((1LL << i) & n){
			if(l) rep(j, i + 1) ans.pb(mp(i, j));
			else for(int j = i; j >= 0; j--) ans.pb(mp(i, j));
			l ^= 1;
		}
		else{
			if(l) ans.pb(mp(i, 0));
			else ans.pb(mp(i, i));
			num--;
		}
	}
	while(num--){
		if(l) ans.pb(mp(st, 0));
		else ans.pb(mp(st, st));
		st++;
	}
	for(pi x : ans){
		cout << x.fi + 1 << " " << x.se + 1 << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << endl;
		solve();
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
