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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
vector<pi> g[mxN];
set<pi> st[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int ans = 0;
	rep(i, m){
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		int uwu = 1;
		auto it = st[a].lb({w, -1});
		if(it != st[a].begin()){
			it--;
			uwu = max(uwu, (*it).se + 1);
		}
		ans = max(ans, uwu);

		auto ite = st[b].lb({w, uwu});
		int f = 0;
		if(ite != st[b].begin()){
			ite--;
			if((*ite).se < uwu){
				if((*ite).fi == w) st[b].erase(ite);
				f = 1;
			}
		}
		else f = 1;

		ite = st[b].lb({w, uwu});
		if(ite != st[b].end()){
			if((*ite).fi == w && uwu <= (*ite).se) f = 0;
		}

		if(f == 1){
			st[b].insert({w, uwu});
			auto owo = st[b].find({w, uwu});
			if(owo != st[b].end()){
				owo++;
				while(owo != st[b].end()){
					if((*owo).se <= uwu) owo = st[b].erase(owo);
					else break;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
