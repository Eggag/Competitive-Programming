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

int x(int i, int j){
	cout << "XOR " << i + 1 << " " << j + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int o(int i, int j){
	cout << "OR " << i + 1 << " " << j + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int a(int i, int j){
	cout << "AND " << i + 1 << " " << j + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int aXb = x(0, 1), bXc = x(1, 2);
	int aOc = o(0, 2), bOc = o(1, 2), aOb = o(0, 1);
	vi a(n);
	rep(i, 30){
		int j = (aXb & (1 << i)), k = (bXc & (1 << i));
		if(j && k){
			int l = (aOc & (1 << i));
			if(l){
				a[0] |= (1 << i);
				a[2] |= (1 << i);
			}
			else a[1] |= (1 << i);
		}
		if(!j && !k){
			int l = (aOc & (1 << i));
			if(l){
				a[0] |= (1 << i);
				a[1] |= (1 << i);
				a[2] |= (1 << i);
			}
		}
		if(!j && k){
			int l = (aOb & (1 << i));
			if(l){
				a[0] |= (1 << i);
				a[1] |= (1 << i);
			}
			else a[2] |= (1 << i);
		}
		if(j && !k){
			int l = (bOc & (1 << i));
			if(l){
				a[1] |= (1 << i);
				a[2] |= (1 << i);
			}
			else a[0] |= (1 << i);
		}
	}
	repn(i, 3, n){
		int xo = x(0, i);
		a[i] = a[0] ^ xo;
	}
	cout << "!";
	rep(i, n) cout << " " << a[i];
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
