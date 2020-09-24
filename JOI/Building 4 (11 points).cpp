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
const int MAXN = 2100;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2 * MAXN][MAXN][2][2]; //[index][number of a's used][current (b is 0, a is 1)][last]

int a[2 * MAXN], b[2 * MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("1.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, 2 * n + 1) cin >> a[i];
	repn(i, 1, 2 * n + 1) cin >> b[i];
	rep(i, 2 * n + 1) rep(j, n + 1) rep(k, 2) rep(l, 2) dp[i][j][k][l] = 0;
	if(a[2] >= a[1]) dp[2][2][1][1] = 1;
	if(a[2] >= b[1]) dp[2][1][1][0] = 1;
	if(b[2] >= a[1]) dp[2][1][0][1] = 1;
	if(b[2] >= b[1]) dp[2][0][0][0] = 1;
	repn(i, 3, 2 * n + 1){
		rep(j, min(n + 1, i + 1)){
			int cur = i;
			int last = i - 1;
			if(a[i] >= a[i - 1]){
				if(j){
					if(dp[last][j - 1][1][1]) dp[cur][j][1][1] = 1;
					else if(dp[last][j - 1][1][0]) dp[cur][j][1][1] = 1;
				}
			}
			if(a[i] >= b[i - 1]){
				if(j){
					if(dp[last][j - 1][0][0]) dp[cur][j][1][0] = 1;
					else if(dp[last][j - 1][0][1]) dp[cur][j][1][0] = 1;
				}

			}
			if(b[i] >= a[i - 1]){
				if(dp[last][j][1][0]) dp[cur][j][0][1] = 1;
				else if(dp[last][j][1][1]) dp[cur][j][0][1] = 1;
			}
			if(b[i] >= b[i - 1]){
				if(dp[last][j][0][0]) dp[cur][j][0][0] = 1;
				else if(dp[last][j][0][1]) dp[cur][j][0][0] = 1;
			}
		}
	}
	//now we need to reconstruct the answer
	if(dp[2 * n][n][0][0]){
		string ans = "B";
		int lst = 0;
		int ind = 2 * n - 1;
		int cur = n;
		while(ans.size() != 2 * n){
			int f = 0;
			if(lst) ans += 'A', f = 1;
			else ans += 'B';
			if(dp[ind][cur][lst][0]) lst = 0;
			else if(dp[ind][cur][lst][1]) lst = 1;
			if(f) cur--;
			ind--;
		}
		reverse(all(ans));
		cout << ans << endl;
	}
	else if(dp[2 * n][n][0][1]){
		string ans = "B";
		int lst = 1;
		int ind = 2 * n - 1;
		int cur = n;
		while(ans.size() != 2 * n){
			int f = 0;
			if(lst) ans += 'A', f = 1;
			else ans += 'B';
			if(dp[ind][cur][lst][0]) lst = 0;
			else if(dp[ind][cur][lst][1]) lst = 1;
			if(f) cur--;
			ind--;
		}
		reverse(all(ans));
		cout << ans << endl;
	}
	else if(dp[2 * n][n][1][1]){
		string ans = "A";
		int lst = 1;
		int ind = 2 * n - 1;
		int cur = n - 1;
		while(ans.size() != 2 * n){
			int f = 0;
			if(lst) ans += 'A', f = 1;
			else ans += 'B';
			if(dp[ind][cur][lst][0]) lst = 0;
			else if(dp[ind][cur][lst][1]) lst = 1;
			if(f) cur--;
			ind--;
		}
		reverse(all(ans));
		cout << ans << endl;
	}
	else if(dp[2 * n][n][1][0]){
		string ans = "A";
		int lst = 0;
		int ind = 2 * n - 1;
		int cur = n - 1;
		while(ans.size() != 2 * n){
			int f = 0;
			if(lst) ans += 'A', f = 1;
			else ans += 'B';
			if(dp[ind][cur][lst][0]) lst = 0;
			else if(dp[ind][cur][lst][1]) lst = 1;
			if(f) cur--;
			ind--;
		}
		reverse(all(ans));
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
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