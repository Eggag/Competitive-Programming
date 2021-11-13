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

set<int> d[mxN];
int vis[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int u;
			cin >> u;
			if(vis[u]) continue;
			for(int j = 1; (j * j) <= u; j++){
				if(u % j == 0){
					d[j].insert(u);
					if(u / j != j) d[u / j].insert(u);
				}
			}
			vis[u] = 1;
		}
		else{
			int x, k, s;
			cin >> x >> k >> s;
			if(x % k != 0 || !d[k].size()){
				cout << -1 << '\n';
				continue;
			}
			auto it = d[k].lb(s - x);
			if(it == d[k].end()) it--;
			int ans = -1, bst = -1;
			while(true){
				if((*it + x) > s){
					if(it == d[k].begin()) break;
					else it--;
				}
				if((*it ^ x) > bst){
					ans = *it;
					bst = (*it ^ x);
				}
				if(*it + x < bst) break;
				if(it == d[k].begin()) break;
				it--;
			}
			cout << ans << '\n';
		}
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
