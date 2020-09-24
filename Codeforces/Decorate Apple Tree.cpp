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

vi g[100005];
vi h;

int dfs(int e){
	int s = (g[e].size()) ? 0 : 1;
	for(int u : g[e]){
		s += dfs(u);
	}
	h.pb(s);
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	dfs(1);
	sort(all(h));
	for(int y : h){
		cout << y << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
