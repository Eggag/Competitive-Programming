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
};

vi g[30];
int vis[30][mxN];

BIT<int> bit[30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k;
	cin >> k;
	string s1;
	cin >> s1;
	string s = "";
	rep(i, k) s += s1;
	rep(i, s.size()) bit[s[i] - 'a'].update(i, 1);
	int n;
	cin >> n;
	rep(i, n){
		int nm;
		char c;
		cin >> nm >> c;
		int l = 0, r = mxN;
		while(l < r){
			int mid = (l + r) / 2;
			if(bit[c - 'a'].query(mid) >= nm) r = mid;
			else l = mid + 1;
		}
		s[l] = ' ';
		bit[c - 'a'].update(l, -1);
	}
	rep(i, s.size()) if(s[i] != ' ') cout << s[i];
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
