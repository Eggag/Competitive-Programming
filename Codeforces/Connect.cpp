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

string g[55];
int x, y, xx, yy;
vector<pi> a1, a2;
pi v[55][55];
int n;

void dfs(int q, int w){
	if(q == xx && w == yy) cout << "0" << endl, exit(0);
	if(q + 1 < n && v[q + 1][w].f == 0 && g[q + 1][w] == '0') v[q + 1][w].f = 1, a1.pb({q + 1, w}), dfs(q + 1, w);
	if(w + 1 < n && v[q][w + 1].f == 0 && g[q][w + 1] == '0') v[q][w + 1].f = 1, a1.pb({q, w + 1}), dfs(q, w + 1);
	if(q - 1 >= 0 && v[q - 1][w].f == 0 && g[q - 1][w] == '0') v[q - 1][w].f = 1, a1.pb({q - 1, w}), dfs(q - 1, w);
        if(w - 1 >= 0 && v[q][w - 1].f == 0 && g[q][w - 1] == '0') v[q][w - 1].f = 1, a1.pb({q, w - 1}), dfs(q, w - 1);
}

void dfs1(int u, int t){
	if(u == x && t == y) cout << "0" << endl, exit(0);
	if(u + 1 < n && v[u + 1][t].s == 0 && g[u + 1][t] == '0') v[u + 1][t].s = 1, a2.pb({u + 1, t}), dfs1(u + 1, t);
        if(t + 1 < n && v[u][t + 1].s == 0 && g[u][t + 1] == '0') v[u][t + 1].s = 1, a2.pb({u, t + 1}), dfs1(u, t + 1);
	if(u - 1 >= 0 && v[u - 1][t].s == 0 && g[u - 1][t] == '0') v[u - 1][t].s = 1, a2.pb({u - 1, t}), dfs1(u - 1, t);
        if(t - 1 >= 0 && v[u][t - 1].s == 0 && g[u][t - 1] == '0') v[u][t - 1].s = 1, a2.pb({u, t - 1}), dfs1(u, t - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> n;
	cin >> x >> y;
	x--, y--;
	cin >> xx >> yy;
	xx--, yy--;
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}
	a1.pb({x, y});
	a2.pb({xx, yy});
	dfs(x, y);
	dfs1(xx, yy);
	int ans = INT_MAX;
	//for(int i = 0; i < a1.size(); i++){
	//	cout << a1[i].f << " " << a1[i].s << endl;
	//}
	//cout << "-------------------------" << endl;
	for(int i = 0; i < a1.size(); i++){
		for(int j = 0; j < a2.size(); j++){
			ans = min(ans, (((a1[i].f - a2[j].f) * (a1[i].f - a2[j].f)) + ((a1[i].s - a2[j].s) * (a1[i].s - a2[j].s))));
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
