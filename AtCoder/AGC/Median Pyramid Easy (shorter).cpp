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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, x;
	cin >> n >> x;
	if(n == 2){
		if(x == 2){
			cout << "Yes" << '\n';
			cout << 1 << '\n';
			cout << 2 << '\n';
			cout << 3 << '\n';
		}
		else cout << "No" << '\n';
		return 0;
	}
	int num = (1 + (n * 2)) / 2;
	if(num == x){
		cout << "Yes" << '\n';
		rep(i, 2 * n - 1) cout << i + 1 << '\n';
	}
	else{
		int off = num - x;
		if(off < 0){
			off = abs(off);
			if(n > (off + 1)){
				cout << "Yes" << '\n';
				repn(i, off, 2 * n - 1) cout << i + 1 << '\n';
				rep(i, off) cout << i + 1 << '\n';
				return 0;
			}
			cout << "No" << endl;
		}
		else{
			if(n > (abs(off) + 1)){
				cout << "Yes" << '\n';
				for(int i = 2 * n - 1, cnt = 0; cnt < abs(off); i--, cnt++){
					cout << i << '\n';
				} 
				repn(i, 0, 2 * n - 1 - abs(off)) cout << i + 1 << '\n';
				return 0;
			}
			cout << "No" << endl;
		}
		return 0;
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
