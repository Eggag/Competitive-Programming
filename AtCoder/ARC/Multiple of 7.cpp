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

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll nm;
	cin >> nm;
	vector<string> res;
	while(nm){
		ll j = 1LL;
		string ans = "";
		for(; j <= nm + 1; j++){
			if(((j * (j + 1)) / 2) > nm){
				j--;
				break;
			}
		}
		rep(i, j) ans += '7';
		res.pb(ans);
		nm -= (j * (j + 1)) / 2;
	}
	vi ls = {1, 2, 3, 4, 5, 6, 8, 9};
	while(true){
		string s1;
		rep(k, res.size()) s1 += (char)('0' + ls[(int)(rng() % 8)]);
		string cur = "";
		rep(i, res.size()){
			cur += res[i];
			if(i != (int)(res.size()) - 1) cur += s1[i];
		}
		int f = 1;
		rep(i, cur.size()) if(cur[i] != '7'){
			int cr = 0;
			repn(j, i, cur.size()){
				cr *= 10;
				cr += (int)(cur[j] - '0');
				cr %= 7;
				if(!cr){
					f = 0;
					break;
				}
			}
			if(!f) break;
		}
		if(f){
			cout << cur << '\n';
			return 0;
		}
	}
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
