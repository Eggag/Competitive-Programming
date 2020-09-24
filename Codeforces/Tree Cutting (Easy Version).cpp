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

int ans = 0;
int red = 0;
int blue = 0;
vi g[300005];
int a[300005];

pi dfs(int c, int p){
	int r = (a[c] == 1), b = (a[c] == 2);
	for(auto e : g[c]){
		if(e == p) continue;
		pi cur = dfs(e, c);
		ans += (cur.f == red && cur.s == 0);
		ans += (cur.f == 0 && cur.s == blue);
		r += cur.f;
		b += cur.s;
	}
	return mp(r, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		red += (a[i] == 1);
		blue += (a[i] == 2);
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1);
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
