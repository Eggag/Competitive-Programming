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

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	if(abs(a - b) > 1){
		cout << "-1\n";
		return;
	}
	if((a - b) == 1){
		if(n > (a * 2)){
			vi p;
			repn(i, 1, n + 1) p.pb(i);
			for(int i = n - 1; i >= 0 && a; i -= 2, a--) swap(p[i], p[i - 1]);
			rep(i, n) cout << p[i] << ' ';
			cout << '\n';
		}
		else cout << "-1\n";
	}
	else if((b - a) == 1){
		if(n > (b * 2)){
			vi p;
			repn(i, 1, n + 1) p.pb(i);
			for(int i = 0; i < (n - 1) && b; i += 2, b--) swap(p[i], p[i + 1]);
			rep(i, n) cout << p[i] << ' ';
			cout << '\n';
		}
		else cout << "-1\n";
	}
	else{
		a++;
		if(n == (a * 2)){
			vi p;
			repn(i, 1, n + 1) p.pb(i);
			for(int i = n - 1; i >= 0 && a; i -= 2, a--) swap(p[i], p[i - 1]);
			rep(i, n) cout << p[i] << ' ';
			cout << '\n';
		}
		else if(n > (a * 2)){
			vi p;
			repn(i, 1, n + 1) p.pb(i);
			int lw = n;
			for(int i = n - 1; i >= 0 && a; i -= 2, a--){
				swap(p[i], p[i - 1]);
				lw = i - 1;
			}
			repn(i, lw, n) cout << p[i] << ' ';
			for(int i = lw - 1; i >= 0; i--) cout << p[i] << ' ';
			cout << '\n';
		}
		else cout << "-1\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
