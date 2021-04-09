#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
	ll b, c;
	cin >> b >> c;
	ll ans = 2;
	if(!b){
		ans = 1LL;
		ll pos1 = c / 2;
		if(pos1 > 0){
			ans += pos1;
			ans += (c - 1) / 2;
		}
	}
	else if(b > 0){
		ll pos = c / 2;
		ll b1 = -b;
		ll betw = abs(b - b1) - 1;
		ans += min(betw, pos);
		ll ad = min(ans - 2, betw - (ans - 2));
		if(c % 2 == 0 && ad == (ans - 2)) ad--;
		ans += max(0LL, ad);
		ll pos1 = (c - 1) / 2;
		if(pos1 > 0){
			ans += pos1;
			ans += (c - 2) / 2;
		}
	}
	else{
		ll pos = (c - 1) / 2;
		ll b1 = -b;
		ll betw = abs(b - b1) - 1;
		ans += min(betw, pos);
		ll ad = min(ans - 2, betw - (ans - 2));
		if((c - 1) % 2 == 0 && ad == (ans - 2)) ad--;
		ans += max(0LL, ad);
		ll pos1 = c / 2;
		if(pos1 > 0){
			ans += pos1;
			ans += (c - 1) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
