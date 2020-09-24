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

int n;
int a[200005], c[200005], v[200005];
int cost = 0;

void dfs(int cur){
	//cycle
	if(v[cur] == 2){
		int v = c[cur];
		int nxt = a[cur];
		while(nxt != cur){
			v = min(v, c[nxt]);
			nxt = a[nxt];
		}
		cost += v;
		return;
	}
	if(v[cur]) return;
	v[cur] = 2;
	dfs(a[cur]);
	v[cur] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dfs(i);
	cout << cost << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
