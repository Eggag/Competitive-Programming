#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 300005;

vi g[maxn];
int ans = 0;
int v[maxn];
int dp[26][maxn];
vi seq;

bool find_cycle(int u){ //topological sort
	if(v[u] == 1) return true;
	if(v[u] == 2) return false;
	v[u] = 1;
	for(auto x : g[u]){
		if(find_cycle(x)) return true;
	}
	v[u] = 2;
	seq.pb(u);
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
	}
	for(int i = 0; i < n; i++){
		if(!v[i]){
			if(find_cycle(i)){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	for(int t = 0; t < 26; t++){
		for(int i = 0; i < seq.size(); i++){
			int p = seq[i];
			int nd = (char)(t + 'a')  == a[p];
			dp[t][p] = nd;
			for(auto y : g[p]){
				dp[t][p] = max(dp[t][p], dp[t][y] + nd);
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < n; j++){
			ans = max(ans, dp[i][j]);
		}
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
