#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
const int MAXN = 250005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ld a[MAXN], s[4 * MAXN], lazy[4 * MAXN], b[MAXN], marked[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = (s[id * 2] + s[id * 2 + 1]);
}

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] = (ld)(lazy[id] * (r - l));
		if((r - l) > 1){
			lazy[2 * id] = lazy[id];
			lazy[2 * id + 1] = lazy[id];
		}
	}
	lazy[id] = 0;
}

void increase(int x, int y, ld u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id * 2, l, mid);
	increase(x, y, u, id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

ld sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> n >> q;
	rep(i, n) cin >> a[i];
	cout << fixed << setprecision(10);
	memset(lazy, 0, sizeof(lazy));
	memset(s, 0, sizeof(s));
	build();
	rep(i, q){
		string s1;
		cin >> s1;
		if(s1[0] == 'g'){
			int pos;
			cin >> pos;
			pos--;
			cout << sum(pos, pos + 1) << endl;
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			ld cur = sum(l, r + 1) / (r - l + 1);
			increase(l, r + 1, cur);
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/