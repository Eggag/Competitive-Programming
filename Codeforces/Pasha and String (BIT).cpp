#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
const int MAXN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind = ind | (ind + 1)){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int m;
	cin >> m;
	BIT<int> bit;
	rep(i, m){
		int a;
		cin >> a;
		bit.update(a - 1, 1);
	}
	vector<char> ans(n);
	rep(i, s.size() / 2){
		if(bit.query(i) % 2 == 0) ans[i] = s[i], ans[n - 1 - i] = s[n - 1 - i];
		else ans[n - 1 - i] = s[i], ans[i] = s[n - 1 - i];
	}
	if(n & 1) ans[n / 2] = s[n / 2];
	for(char x : ans) cout << x;
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
