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
	int n, m, k;
	cin >> n >> m >> k;
	deque<int> dq;
	rep(i, n) dq.pb(i);
	rep(i, k){
		int md = n % m;
		vi vis(n, 0);
		rep(j, md){
			cout << (n / m) + 1 << ' ';
			rep(l, (n / m) + 1){
				int fr = dq.front();
				vis[fr] = 1;
				cout << fr + 1 << ' ';
				dq.pop_front();
				dq.pb(fr);
			}
			cout << '\n';
		}
		vi uwu;
		rep(j, n) if(!vis[j]) uwu.pb(j);
		int ind = 0;
		rep(j,  m - md){
			cout << (n / m) << ' ';
			rep(l, (n / m)) cout << uwu[ind++] + 1 << ' ';
			cout << '\n';
		}
	}
	cout << '\n';
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
