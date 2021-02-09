#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 55;

vi st[mxN];
int dist[50005];
int gd[50005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi b(n);
	rep(i, n) cin >> b[i], b[i]--, st[b[i]].pb(i);
	vector<string> s(k);
	rep(i, k) cin >> s[i];
	set<pair<int, int>> q;
	rep(i, n) dist[i] = 1e9;
	dist[0] = 0;
	q.insert({0, 0});
	while(!q.empty()){
		pair<int, int> cur = *q.begin();
		q.erase(q.begin());
		rep(i, k) if(s[b[cur.se]][i] == '1'){
			for(int x : st[i]) if(!gd[x]){
				if(dist[x] > cur.fi + abs(cur.se - x)){
					q.erase(mp(dist[x], x));
					dist[x] = cur.fi + abs(cur.se - x);
					q.insert(mp(dist[x], x));
				}
				else if((dist[x] + n) < cur.fi) gd[x] = 1;
			}
		}
	}
	if(dist[n - 1] == 1e9) dist[n - 1] = -1;
	cout << dist[n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
