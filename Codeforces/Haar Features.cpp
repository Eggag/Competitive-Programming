#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int s[mxN][mxN], s1[mxN][mxN];

bool cmp(pi a, pi b){
	return (a.fi + a.se) < (b.fi + b.se);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m){
		char c;
		cin >> c;
		if(c == 'W') s[i][j] = s1[i][j] = 1;
		else s[i][j] = s1[i][j] = -1;
	}
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	rep(i, n) rep(j, m) if(s[i][j] != 1) pq.push({i, j}); //need to fix
	//now we keep processing
	int ans = 1e9;
	int cur = 1;
	while(pq.size()){
		pi cur1 = pq.top();
		pq.pop();
		if(s[cur1.fi][cur1.se] != 1){
			int dif = 1 - s[cur1.fi][cur1.se];
			rep(i, cur1.fi + 1) rep(j, cur1.se + 1){
				if(s[i][j] == 1) pq.push({i, j});
				s[i][j] += dif;
			}
			cur++;
		}
	}
	swap(s, s1);
	ans = min(ans, cur);
	while(pq.size()) pq.pop();
	rep(i, n) rep(j, m) if(s[i][j] != -1) pq.push({i, j}); //need to fixA
	cur = 1;
	while(pq.size()){
		pi cur1 = pq.top();
		pq.pop();
		if(s[cur1.fi][cur1.se] != -1){
			int dif = -1 - s[cur1.fi][cur1.se];
			rep(i, cur1.fi + 1) rep(j, cur1.se + 1){
				if(s[i][j] == -1) pq.push({i, j});
				s[i][j] += dif;
			}
			cur++;
		}
	}
	ans = min(ans, cur);
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
