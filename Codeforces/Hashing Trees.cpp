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
	int h;
	cin >> h;
	vi a(h + 1);
	rep(i, h + 1) cin >> a[i];
	int f = 0;
	repn(i, 1, h + 1) if(a[i] > 1 && a[i - 1] > 1) f = 1;
	if(!f){
		cout << "perfect\n";
		return 0;
	}
	cout << "ambiguous\n";
	vi a1, b1;
	a1.pb(0), b1.pb(0);
	int f1 = 0;
	int lst = 1;
	repn(i, 1, h + 1){
		if(!f1 && a[i] > 1 && a[i - 1] > 1){
			a1.pb(lst - 1);
			rep(j, a[i]){
				if(j) a1.pb(lst);
				b1.pb(lst);
			}
			f1 = 1;
		}
		else{
			rep(j, a[i]) a1.pb(lst), b1.pb(lst);
		}
		lst += a[i];
	}
	for(int x : a1) cout << x << " ";
	cout << '\n';
	for(int x : b1) cout << x << " ";
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
