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
const int mxN = 305 * 305;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int te = 1;
array<int, 3> ed[mxN];
int vs[mxN];
map<pi, int> cnt;

void ask(vi c, vi d){
	cout << "? " << (int)(c.size()) << ' ' << (int)(d.size()) << endl;
	rep(i, c.size()){
		cout << c[i];
		if(i == (int)(c.size()) - 1) cout << endl;
		else cout << ' ';
	}
	rep(i, d.size()){
		cout << d[i];
		if(i == (int)(d.size()) - 1) cout << endl;
		else cout << ' ';
	}
	int r;
	cin >> r;
	rep(i, r){
		int x;
		cin >> x;
		vs[x] = te;
	}
}

void solve(vi owo){
	if((int)(owo.size()) <= 1) return;
	int n1 = (int)(owo.size());
	vi a, b;
	rep(i, n1){
		if(i < (n1 / 2)) a.pb(owo[i]);
		else b.pb(owo[i]);
	}
	ask(a, b);
	rep(i, a.size()) rep(j, b.size()){
		if(cnt[mp(a[i], b[j])]){
			int id = cnt[mp(a[i], b[j])];
			if(vs[id] != te) ed[id][2] = 1;
		}
		else if(cnt[mp(b[j], a[i])]){
			int id = cnt[mp(b[j], a[i])];
			if(vs[id] == te) ed[id][2] = 1;
		}
	}
	te++;
	solve(a);
	solve(b);
}

int main(){
	int n, m;
	cin >> n >> m;
	repn(i, 1, m + 1){
		int u, v;
		cin >> u >> v;
		ed[i] = array<int, 3>{u, v, 0};
		cnt[mp(u, v)] = i;
	}
	vi uwu;
	repn(i, 1, n + 1) uwu.pb(i);
	solve(uwu);
	cout << "! ";
	repn(i, 1, m + 1){
		if(ed[i][1] > ed[i][0]) ed[i][2] ^= 1;
		cout << ed[i][2];
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
