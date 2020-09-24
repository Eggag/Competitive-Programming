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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN], cr[mxN];

struct cmp{
	bool operator()(int b, int c) const{
		return a[b] > a[c];
	}
};

set<int, cmp> st[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	multiset<int> mx;
	rep(i, n){
		int b;
		cin >> a[i + 1] >> b;
		if(st[b].size()){
			auto it = mx.find(a[*st[b].begin()]);
			if(it != mx.end()) mx.erase(it);
		}
		st[b].insert(i + 1);
		mx.insert(a[*st[b].begin()]);
		cr[i + 1] = b;
	}
	rep(i, q){
		int c, d;
		cin >> c >> d;
		//we erase
		auto it1 = mx.find(a[*st[cr[c]].begin()]);
		if(it1 != mx.end()) mx.erase(it1);
		auto it = st[cr[c]].find(c);
		if(it != st[cr[c]].end()) st[cr[c]].erase(st[cr[c]].find(c));
		if(st[cr[c]].size()) mx.insert(a[*st[cr[c]].begin()]);
		//we insert
		if(st[d].size()){
			auto it2 = mx.find(a[*st[d].begin()]);
			if(it2 != mx.end()) mx.erase(it2);
		}
		st[d].insert(c);
		mx.insert(a[*st[d].begin()]);
		cr[c] = d;
		cout << *mx.begin() << endl;
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
