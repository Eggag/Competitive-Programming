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
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dist[20005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, 20005) dist[i] = 1e9;
	if(n >= m){
		cout << n - m << endl;
		return 0;
	}
	queue<pi> q;
	q.push(mp(n, 0));
	while(q.size()){
		pi cur = q.front();
		q.pop();
		dist[cur.fi] = min(cur.se, dist[cur.fi]);
		if((cur.fi * 2) < (2 * m) && dist[cur.fi * 2] > cur.se + 1) q.push(mp(cur.fi * 2, cur.se + 1));
		if(cur.fi >= 1 && dist[cur.fi - 1] > cur.se + 1) q.push(mp(cur.fi - 1, cur.se + 1));
	}
	cout << dist[m] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
