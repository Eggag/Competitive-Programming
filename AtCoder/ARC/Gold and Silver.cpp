#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
	vi ans(n, 0);
	int mx = 0, ind = -1, f = 0, mn = 2e9, ind1 = -1;
	rep(i, n){
		if(!f){
			if(a[i] > mx) mx = a[i], ind = i;
			else{
				mn = a[i];
				ind1 = i;
				f = 1;
			}
		}
		else{
			if(a[i] < mn) mn = a[i], ind1 = i;
			else{
				ans[ind] = ans[ind1] = 1;
				ind = i, ind1 = -1;
				mx = a[i], mn = 2e9;
				f = 0;
			}
		}
	}
	if(ind != -1 && ind1 != -1) ans[ind] = ans[ind1] = 1;
	rep(i, n) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
