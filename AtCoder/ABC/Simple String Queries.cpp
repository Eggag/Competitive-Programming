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
const int MAXN = 5e5 + 100;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind += (ind & (-ind))){
			bit[ind] += delta;
			if(!ind) break;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ; ind -= (ind & (-ind))){
			sum += bit[ind];
			if(ind <= 0) break;
		}
		return sum;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	BIT<int> bit1[26];
	rep(i, s.size()) bit1[s[i] - 'a'].update(i, 1);
	int q;
	cin >> q;
	rep(j, q){
		int t;
		cin >> t;
		if(t == 1){
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			bit1[s[pos] - 'a'].update(pos, -1);
			s[pos] = c;
			bit1[s[pos] - 'a'].update(pos, 1);
		}
		else{
			int l, r;
			cin >> l >> r;
			int ans = 0;
			l -= 2, r--;
			rep(i, 26){
				ans += (((bit1[i].query(r) - (l >= 0 ? bit1[i].query(l) : 0))) > 0);
			}
			cout << ans << endl;
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
