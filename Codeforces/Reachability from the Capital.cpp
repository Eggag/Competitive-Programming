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

int vis[5005];
vi r[5005]; //which vertices can be reached from i
vi g[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
	}
	rep(i, n){
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int u : g[cur]) if(!vis[u]){
				vis[u] = 1;
				q.push(u);
			}
		}
		rep(j, 5005) if(vis[j]) r[i].pb(j);
	}	
	int num = 0, ans = 0;
	vi vis1(n, 0);
	rep(i, r[s].size()) if(!vis1[r[s][i]]){
		vis1[r[s][i]] = 1;
		num++;
	}
	while(num < n){
		int mx = 0, bst = -1;
		rep(i, n) if(!vis1[i]){
			int cur = 0;
			rep(j, r[i].size()) if(!vis1[r[i][j]]) cur++;
			if(cur > mx){
				mx = cur;
				bst = i;
			}
		}
		rep(i, r[bst].size()) if(!vis1[r[bst][i]]){
			vis1[r[bst][i]] = 1;
			num++;
		}
		ans++;
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
