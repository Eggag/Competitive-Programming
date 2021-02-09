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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis[5005][505];
pi pre[5005][505];
int ans[5005][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int d, s;
	cin >> d >> s;
	queue<pi> q;
	q.push({0, 0});
	vis[0][0] = 1;
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 10){
			int sm = cur.fi + i;
			int md = ((cur.se * 10) + i) % d;
			if(!vis[sm][md] && sm <= s){
				vis[sm][md] = 1;
				pre[sm][md] = cur;
				ans[sm][md] = i;
				q.push(mp(sm, md));
			}
		}
	}
	if(!vis[s][0]){
		cout << -1 << endl;
		return 0;
	}
	pi cur = mp(s, 0);
	string ret = "";
	while(cur.fi != 0){
		ret += (char)('0' + ans[cur.fi][cur.se]);
		cur = pre[cur.fi][cur.se];
	}
	reverse(all(ret));
	cout << ret << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
