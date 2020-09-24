#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0 , -1};

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

string g[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> g[i];
	rep(i, n) rep(j, m) if(g[i][j] == '.'){
		bool f = 1;
		rep(k, 8){
			int nx = i + dx[k];
			int ny = j + dy[k];
			if(nx >= 0 && ny >= 0 && nx < n && ny < m){
				if(g[nx][ny] == '*'){
					f = 0;
					break;
				}
			}
		}
		if(!f){
			cout << "NO" << endl;
			return 0;
		}
	}
	rep(i, n) rep(j, m){
		if(g[i][j] <= '8' && g[i][j] >= '1'){
			int cnt = 0;
			rep(k, 8){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(nx < n && ny < m && nx >= 0 && ny >= 0){
					if(g[nx][ny] == '*') cnt++;
				}
			}
			if(cnt != (g[i][j] - '0')){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
