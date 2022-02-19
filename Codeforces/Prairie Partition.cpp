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
const int mxB = 45;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int uwu[mxB], owo[mxB];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	int mx = -1;
	rep(i, mxB){
		uwu[i] = 1e9;
		rep(j, n) if(a[j] == (1LL << i)) uwu[i] = min(uwu[i], j), owo[i]++;
		if(owo[i]) mx = i;
	}
	if(mx == -1 || (1LL << (mx + 1)) < a[n - 1]){
		cout << -1 << '\n';
		return 0;
	}
	vi ans;
	repn(i, 1, n + 1){
		if(owo[0] < i) break;
		int cr = i, lft = 0;
		if(owo[0] > i) lft = owo[0] - i;
		int f = 1;
		repn(j, 1, mxB){
			if(owo[j] && !cr){
				f = 0;
				break;
			}
			if(owo[j]) lft += uwu[j] - uwu[j - 1] - owo[j - 1];
			else lft += n - uwu[j - 1] - owo[j - 1];
			if(owo[j] < cr){
				lft = max(0, lft - (cr - owo[j]));
				cr = owo[j];
			}
			else lft += owo[j] - cr;
			if(!cr && !owo[j]) break;
		}
		if(cr || lft) f = 0;
		if(f) ans.pb(i);
	}
	if(!ans.size()) cout << -1 << '\n';
	else{
		for(int x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
