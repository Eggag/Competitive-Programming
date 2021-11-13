#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
ll k;
vi g[mxN];
vi p[mxN];
map<pi, int> ed;
vector<vi> gr;

bool cmp(vi a, vi b){
	return (int)(a.size()) > (int)(b.size());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		ed[mp(a, b)] = ed[mp(b, a)] = i;
	}
	vi vis(n, 0);
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	ll ans = 1LL;
	rep(i, n){
		queue<int> q1;
		vi cur;
		while(!q.empty()){
			int tp = q.front();
			q.pop();
			for(int x : g[tp]){
				if(!vis[x]){
					vis[x] = 1;
					q1.push(x);
					cur.pb(x);
				}
				p[x].pb(tp);
			}
		}
		for(int x : cur){
			vi nw;
			for(int y : p[x]) nw.pb(ed[mp(x, y)]);
			if(ans < k) ans *= (ll)(p[x].size());
			gr.pb(nw);
		}
		q = q1;
		if(q.empty()) break;
	}
	k = min(k, ans);
	string emp = string(m, '0');
	vector<string> cand = {emp};
	sort(all(gr), cmp);
	rep(i, gr.size()){
		if((int)(cand.size()) == k){
			rep(j, cand.size()) cand[j][gr[i][0]] = '1';
		}
		else{
			vector<string> ncand;
			rep(j, cand.size()){
				if((int)(ncand.size()) >= k) break;
				for(int x : gr[i]){
					if((int)(ncand.size()) >= k) break;
					cand[j][x] = '1';
					ncand.pb(cand[j]);
					cand[j][x] = '0';
				}
			}
			swap(cand, ncand);
		}
	}
	cout << (int)(cand.size()) << '\n';
	for(string x : cand) cout << x << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
