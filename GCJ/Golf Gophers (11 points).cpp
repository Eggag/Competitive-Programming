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

int t, n, m;

void solve(){
	int ans = 0;
	rep(i, n){
		string ret;
		rep(j, 18){
			int num = (18 - (rand() & 1) - (rand() & 1));
			string s = to_string(num);
			ret += s;
			if(j != 17) ret += ' ';
		}
		cout << ret << endl;
		int cur = 0;
		rep(j, 18){
			int x;
			cin >> x;
			if(x == -1) exit(0);
			cur += x;
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	int res;
	cin >> res;
	if(res == -1) exit(0);
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> t >> n >> m;
	for(int i = 1; i <= t; i++){
		debug(i);
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
