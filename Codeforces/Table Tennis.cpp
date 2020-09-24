#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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
	ll k, n;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll cnt = 0;
	for(;;){
		if(cnt >= k || a[0] == n){
			cout << a[0] << endl;
			return 0;
		}
		if(a[0] > a[1]){
			cnt++;
			int cur = a[1];
			a.erase(a.begin() + 1);
			a.pb(cur);
		}
		else{
			cnt = 1;
			int cur = a[0];
			a.erase(a.begin());
			a.pb(cur);
		}
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
