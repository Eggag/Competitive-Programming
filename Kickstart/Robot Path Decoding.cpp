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
const int MOD = 1e9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s;

pair<ll, ll> go(int l, int r){
	ll hor = 0, ver = 0;
	repn(i, l, r){
		if(s[i] >= '1' && s[i] <= '9'){
			int bal = 0, br = 0;
			repn(j, i + 1, r){
				if(s[j] == '(') bal++;
				else if(s[j] == ')') bal--;
				if(!bal){
					br = j;
					break;
				}
			}
			pair<ll, ll> nxt = go(i + 2, br);
			(hor += (ll)(1LL * nxt.fi * (s[i] - '0'))) %= MOD;
			(ver += (ll)(1LL * nxt.se * (s[i] - '0'))) %= MOD;
			i = br;
			continue;
		}
		if(s[i] == 'N') ver--;
		else if(s[i] == 'S') ver++;
		else if(s[i] == 'W') hor--;
		else hor++;
		hor %= MOD;
		ver %= MOD;
	}
	return mp(hor, ver);
}

void solve(){
	cin >> s;
	pair<ll, ll> ans = go(0, (int)(s.size()));
	if(ans.fi < 0) ans.fi += 1e9;
	if(ans.se < 0) ans.se += 1e9;
	cout << ans.fi + 1 << " " << ans.se + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
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
