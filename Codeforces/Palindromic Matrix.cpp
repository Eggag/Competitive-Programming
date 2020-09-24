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

int m[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(sq(n));
	memset(m, 0, sizeof(m));
	rep(i, sq(n)) cin >> a[i], m[a[i]]++;
	if(n & 1){
		vi pos, pos1;
		rep(i, 1005){
			if(m[i]) rep(j, (m[i] / 4)) pos.pb(i);
			m[i] %= 4;
			while(m[i]--) pos1.pb(i);
		}
		int ans[n][n];
		rep(i, n) rep(j, n) ans[i][j] = -1;
		rep(i, n / 2) rep(j, n / 2){
			if(!pos.size()){
				cout << "NO" << endl;
				return 0;
			}
			int now = pos[(int)pos.size() - 1];
			pos.pop_back();
			ans[i][j] = now;
			ans[i][n - j - 1] = now;
			ans[n - i - 1][j] = now;
			ans[n - i - 1][n - j - 1] = now;
		}
		int m1[1005];
		memset(m1, 0, sizeof(m1));
		rep(i, pos.size()){
			rep(j, 4) pos1.pb(pos[i]);
		}
		rep(i, pos1.size()) m1[pos1[i]]++;
		vi pos2;
		int sp = 0;
		rep(i, 1005){
			if(m1[i]){
				rep(j, (m1[i] / 2)) pos2.pb(i);
				if(m1[i] & 1) sp = i; 
			}
		}
		ans[n / 2][n / 2] = sp;
		rep(i, n / 2){
			if(!pos2.size()){
				cout << "NO" << endl;
				return 0;
			}
			int num = pos2[pos2.size() - 1];
			pos2.pop_back();
			ans[n / 2][i] = num;
			ans[n / 2][n - i - 1] = num;
		}
		rep(i, n / 2){
			if(!pos2.size()){
				cout << "NO" << endl;
				return 0;
			}
			int num = pos2[pos2.size() - 1];
			pos2.pop_back();
			ans[i][n / 2] = num;
			ans[n - i - 1][n / 2] = num;
		}
		cout << "YES" << endl;
		rep(i, n){
			rep(j, n){
				if(ans[i][j] == -1){
					cout << "NO" << endl;
					return 0;
				}
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		vi pos;
		rep(i, 1005){
			if(m[i] % 4 != 0){
				cout << "NO" << endl;
				return 0;
			}
			else if(m[i]) rep(j, (m[i] / 4)) pos.pb(i);
		}
		int ans[n][n];
		rep(i, n) rep(j, n) ans[i][j] = -1;
		rep(i, n / 2) rep(j, n / 2){
			if(!pos.size()){
				cout << "NO" << endl;
				return 0;
			}
			int now = pos[(int)pos.size() - 1];
			pos.pop_back();
			ans[i][j] = now;
			ans[i][n - j - 1] = now;
			ans[n - i - 1][j] = now;
			ans[n - i - 1][n - j - 1] = now;
		}
		cout << "YES" << endl;
		rep(i, n){
			rep(j, n){
				if(ans[i][j] == -1){
					cout << "NO" << endl;
					return 0;
				}
				cout << ans[i][j] << " ";
			}
			cout << endl;
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
