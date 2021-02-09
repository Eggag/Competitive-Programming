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
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi hi;
	int f = 0;
	rep(i, n){
		int h = -1;
		for(int j = 31; j >= 0; j--) if(a[i] & (1 << j)){
			h = j;
			break;
		}
		if(hi.size() && hi[0] != h){
			if(hi.size() >= 3){
				cout << 1 << endl;
				return 0;
			}
			hi.clear();
		}
		hi.pb(h);
		if(hi.size() > 1) f = 1;
	}
	if(hi.size() > 1) f = 1;
	if(hi.size() >= 3){
		cout << 1 << endl;
		return 0;
	}
	if(!f){
		cout << -1 << endl;
		return 0;
	}
	int mn = 1e9;
	rep(i, n) repn(j, i + 1, n){
		int nm = j - i;
		int x = a[i];
		repn(k, i + 1, j + 1) x ^= a[k];
		if(i > 0 && x < a[i - 1]) mn = min(mn, nm);
		if(j < (n - 1) && x > a[j + 1]) mn = min(mn, nm);
	}
	rep(i, n) repn(j, i + 1, n) repn(k, j + 2, n){
		int nm = k - i - 1;
		int x = a[i];
		repn(l, i + 1, j + 1) x ^= a[l];
		int x1 = a[j + 1];
		repn(l, j + 2, k + 1) x1 ^= a[l];
		if(i > 0 && x < a[i - 1]) mn = min(mn, nm);
		if(x1 < x) mn = min(mn, nm);
		if(k < (n - 1) && x1 > a[k + 1]) mn = min(mn, nm);
	}
	if(mn == 1e9) mn = -1;
	cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
