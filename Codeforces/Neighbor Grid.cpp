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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[305][305];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	rep(i, n) rep(j, m) if(a[i][j] > 4){
		cout << "NO" << endl;
		return;
	}
	rep(i, n) rep(j, m) if(a[i][j]){
		int cnt = 0;
		rep(k, 4){
			int x = i + dx[k], y = j + dy[k];
			if(x >= 0 && y >= 0 && y < m && x < n && a[x][y]) cnt++;
		}
		if(cnt >= a[i][j]) a[i][j] = cnt;
		else{
			rep(k, 4){
				if(cnt == a[i][j]) break;
				int x = i + dx[k], y = j + dy[k];
				if(x >= 0 && y >= 0 && y < m && x < n && !a[x][y]){
					a[x][y] = 1;
					cnt++;
				}

			}
		}
		if(cnt < a[i][j]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	rep(i, n){
		rep(j, m){
			int cnt = 0;
			rep(k, 4){
				int x = i + dx[k], y = j + dy[k];
				if(x >= 0 && y >= 0 && y < m && x < n && a[x][y]) cnt++;
			}
			if(!a[i][j]) cnt = 0;
			cout << cnt << " ";
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
