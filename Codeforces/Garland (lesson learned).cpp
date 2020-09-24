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
const int mxN = 2e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
};

int tim = 0;
int st[mxN], en[mxN];
int p[mxN], t[mxN], d[mxN], d1[mxN];
vi g[mxN];
BIT<int> bit;
int tot = 0, cnt = 0;

void dfs(int cur, int prev){
	d[cur] = t[cur];
	st[cur] = tim++;
	for(int u : g[cur]) if(u != prev){
		dfs(u, cur);
		d[cur] += d[u];
	}
	en[cur] = tim++;
	if(d[cur] == (tot / 3)) bit.update(st[cur], 1), cnt++;
}

set<int> pos;

void dfs1(int cur, int prev){
	if(d[cur] == (tot / 3)) d1[cur] = 1;
	for(int u : g[cur]) if(u != prev){
		dfs1(u, cur);
		d1[cur] += d1[u];
	}
	if(d1[cur] == 1 && d[cur] == (tot / 3)) pos.insert(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int rt = 0;
	rep(i, n){
		cin >> p[i] >> t[i];
		tot += t[i];
		p[i]--;
		if(p[i] >= 0){
			g[i].pb(p[i]);
			g[p[i]].pb(i);
		}
		else rt = i;
	}
	if(tot % 3 != 0){
		cout << -1 << endl;
		return 0;
	}
	dfs(rt, -1);
	dfs1(rt, -1);
	if(pos.size() > 1){
		auto it = pos.begin();
		auto it1 = it;
		it1++;
		cout << *it + 1 << " " << *it1 + 1 << endl;
		return 0;
	}
	rep(i, n) if(i != rt){
		if(d[i] == 2 * (tot / 3)){
			int num = bit.query(en[i]) - bit.query(st[i]);
			if(num){
				rep(j, n) if(d[j] == (tot / 3) && j != i && j != rt){
					if((st[j] >= st[i] && st[j] <= en[i])){
						cout << i + 1 << " " << j + 1 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
