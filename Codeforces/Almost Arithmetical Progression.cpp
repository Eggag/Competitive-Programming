#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	set<int> pos;
	int ans = 0;
	rep(i, n) cin >> a[i], g[a[i]].pb(i), pos.insert(a[i]), ans = max(ans, (int)g[a[i]].size());
	vi b(all(pos));
	rep(i, b.size()) rep(j, b.size()) if(b[i] != b[j]){
		//we iterate over both lists
		int x = 0, y = 0;
		int cnt = 0;
		int lst = -1e9;
		while(x < g[b[i]].size() || y < g[b[j]].size()){
			if(cnt % 2 == 0){
				while(x < g[b[i]].size() && g[b[i]][x] < lst) x++;
				if(x != g[b[i]].size()){
					lst = g[b[i]][x];
					cnt++;
					x++;
				}
				else break;
			}
			else{
				while(y < g[b[j]].size() && g[b[j]][y] < lst) y++;
				if(y != g[b[j]].size()){
					lst = g[b[j]][y];
					cnt++;
					y++;
				}
				else break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
