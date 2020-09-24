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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = a + b + c + d;
	if(n == 1){
		cout << "YES" << endl;
		if(a) cout << 0 << endl;
		if(b) cout << 1 << endl;
		if(c) cout << 2 << endl;
		if(d) cout << 3 << endl;
		return 0;
	}
	vi ans(n);
	rep(i, 4) rep(j, 4){
		int a1 = a, b1 = b, c1 = c, d1 = d;
		vi done(n, 0);
		vi cur(n, -1);
		if(i == 2){
			if(c1){
				cur[0] = 2;
				c1--;
			}
			else continue;
			done[0] = 1;
		}
		if(i == 3){
			if(d1){
				cur[0] = 3;
				d1--;
			}
			else continue;
			if(c1){
				cur[1] = 2;
				c1--;
			}
			else continue;
			done[0] = done[1] = 1;
		}
		//now we do the end
		if(j == 0){
			//we do 2 1 0
			if(a1){
				cur[n - 1] = 0;
				a1--;
			}
			else continue;
			if(b1){
				cur[n - 2] = 1;
				b1--;
			}
			else continue;
			done[n - 1] = done[n - 2] = 1;
		}
		if(j == 1){
			if(b1){
				cur[n - 1] = 1;
				b1--;
			}
			else continue;
			done[n - 1] = 1;
		}
		int st = 0; //0 and 1
		int f1 = 1;
		rep(k, n) if(!done[k]){
			if(!k){
				if(i == 0){
					if(a1) cur[k] = 0, a1--;
					else f1 = 0;
				}
				else{
					if(b1) cur[k] = 1, b1--;
					else f1 = 0;
				}
				continue;
			}
			if(st == 0){
				if(cur[k - 1] == 2){
					if(b1) cur[k] = 1, b1--;
					else if(d1){
						st += 2;
						d1--;
						cur[k] = 3;
					}
					else continue;
				}
				if(cur[k - 1] == 1){
					if(a1) cur[k] = 0, a1--;
					else if(c1){
						st++;
						cur[k] = 2;
						c1--;
					}
					else f1 = 0;
				}
				if(cur[k - 1] == 0){
					if(b1) cur[k] = 1, b1--;
					else f1 = 0;
				}
			}
			else if(st == 1){
				if(cur[k - 1] == 1){
					if(c1) cur[k] = 2, c1--;
					else f1 = 0;
				}
				if(cur[k - 1] == 2){
					if(b1) cur[k] = 1, b1--;
					else if(d1){
						st++;
						cur[k] = 3;
						d1--;
					}
					else f1 = 0;
				}
			}
			else if(st == 2){
				if(cur[k - 1] == 2){
					if(d1) cur[k] = 3, d1--;
					else f1 = 0;
				}
				if(cur[k - 1] == 3){
					if(c1) cur[k] = 2, c1--;
					else f1 = 0;
				}
			}
		}
		int f = f1;
		repn(k, 1, n) if(abs(cur[k] - cur[k - 1]) != 1) f = 0;
		if(f){
			cout << "YES" << endl;
			rep(k, n) cout << cur[k] << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
