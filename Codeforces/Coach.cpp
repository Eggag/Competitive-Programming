#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int v[50];
vi g[50];
int cc;
vi cur1;

void dfs(int cur){
	v[cur] = 1;
	cc++;
	cur1.pb(cur);
	for(auto u : g[cur]) if(!v[u]) dfs(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(v, 0, sizeof(v));
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(b);
	}
	vector<vector<vi>> con(4);
	vi cnt(4, 0);
	rep(i, n) if(!v[i]){
		cc = 0;
		cur1.clear();
		dfs(i);
		if(cc > 3){
			cout << -1 << endl;
			return 0;
		}
		con[cc].pb(cur1);
		cnt[cc]++;
	}
	if(cnt[1] >= cnt[2]){
		//we can merge all 1s and 2s together
		rep(i, con[3].size()){
			rep(j, con[3][i].size()){
				cout << con[3][i][j] + 1 << " ";
			}
			cout << endl;
		}
		//pair ones and twos
		rep(i, con[2].size()){
			rep(j, con[2][i].size()){
				cout << con[2][i][j] + 1 << " ";
			}
			cout << con[1][i][0] + 1 << endl;
		}
		//take care of leftover ones
		int diff = cnt[1] - cnt[2];
		int count = 0;
		for(int i = con[1].size() - 1; i >= (cnt[1] - diff); i--){
			cout << con[1][i][0] + 1 << " ";
			count++;
			if(count == 3){
				count = 0;
				cout << endl;
			}
		}
	}
	else{
		cout << -1 << endl;
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
