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
	T sum(int ind){
		return query(ind) - query(ind - 1);
	}
};

set<int> st[70];

int h(char c){
	if(c >= '0' && c <= '9') return (int)(c - '0');
	if(c >= 'a' && c <= 'z') return (int)(c - 'a') + 10;
	if(c >= 'A' && c <= 'Z') return (int)(c - 'A') + 37;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	rep(i, s.size()) st[h(s[i])].insert(i);
	BIT<int> bit;
	rep(i, m){
		int L, R;
		char c;
		cin >> L >> R >> c;
		L--, R--;
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if((mid - bit.query(mid)) >= L) r = mid;
			else l = mid + 1;
		}
		L = l;
		l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if((mid - bit.query(mid)) >= R) r = mid;
			else l = mid + 1;
		}
		R = l;
		auto p = st[h(c)].lb(L);
		while(p != st[h(c)].end() && *p <= R){
			int pos = *p;
			auto next = p;
			next++;
			st[h(c)].erase(p);
			p = next;
			bit.update(pos, 1);
		}
	}
	rep(i, n) if(!bit.sum(i)) cout << s[i];
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
