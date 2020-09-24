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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int l = 0, r = m - 1;
	rep(j, m / 2){
		if(!j){
			//we start in upper left
			int up = 0, dw = n - 1;
			rep(i, 2 * n){
				if(i % 2 == 0){
					cout << up + 1 << " " << l + 1 <<  '\n';
					up++;
				}
				else{
					cout << dw + 1 << " " << r + 1 <<  '\n';
					dw--;
				}
			}
		}
		else{
			if(j & 1){
				int up = 0, dw = n - 1;
				rep(i, 2 * n){
					if(i % 2 == 0){
						cout << dw + 1 << " " << l + 1 <<  '\n';
						dw--;
					}
					else{
						cout << up + 1 << " " << r + 1 <<  '\n';
						up++;
					}
				}
			}
			else{
				int up = 0, dw = n - 1;
				rep(i, 2 * n){
					if(i % 2 == 0){
						cout << up + 1 << " " << l + 1 <<  '\n';
						up++;
					}
					else{
						cout << dw + 1 << " " << r + 1 <<  '\n';
						dw--;
					}
				}
			}
		}
		l++, r--;
	}
	if(m & 1){
		int u = 0, d = n - 1;
		rep(i, n){
			if(i % 2 == 0) cout << u + 1 << " " << l + 1 << '\n', u++;
			else cout << d + 1 << " " << r + 1 << '\n', d--;
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
