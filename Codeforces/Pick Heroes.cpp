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

int op[3005];

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi p(2 * n);
	rep(i, 2 * n) cin >> p[i];
	rep(i, 2 * n) op[i] = -1;
	vector<pi> pos;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		pos.pb({a, b});
		op[a] = b;
		op[b] = a;
	}
	int t;
	cin >> t;
	int cnt = 0;
	int lst = -1;
	vi vis(2 * n, 0);
	while(cnt < (2 * n)){
		if(t & 1){
			if(lst == -1 || op[lst] == -1 || (op[lst] >= 0 && vis[op[lst]])){
				int bst = -1;
				int mx = 0;
				rep(i, pos.size()){
					if(!vis[pos[i].fi] && !vis[pos[i].se]){
						if(abs(p[pos[i].fi] - p[pos[i].se]) > mx){
							if(p[pos[i].fi] > p[pos[i].se]) bst = pos[i].fi;
							else bst = pos[i].se;
							mx = abs(p[pos[i].fi] - p[pos[i].se]);
						}	
					}
				}
				if(bst == -1){
					int mx = 0;
					rep(i, 2 * n) if(!vis[i]){
						if(p[i] > mx){
							mx = p[i];
							bst = i;
						}
					}
				}
				vis[bst] = 1;
				cout << bst + 1 << endl;
			}
			else{
				int take = op[lst];
				vis[take] = 1;
				cout << take + 1 << endl;
			}
		}
		else{
			int x;
			cin >> x;
			x--;
			vis[x] = 1;
			lst = x;
		}
		cnt++;
		t++;
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
