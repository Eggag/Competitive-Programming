#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

int dp[3005][3005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	for(int i = 1; i <= a.size(); i++){
		for(int j = 1; j <= b.size(); j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	int x = a.size();
	int y = b.size();
	string ans = " ";
	while(x && y){
		if(a[x - 1] == b[y - 1]){
			ans += a[x - 1];
			x--;
			y--;
		}
		else if(dp[x - 1][y] > dp[x][y - 1]){
			x--;
		}
		else{
			y--;
		}

	}
	reverse(all(ans));
	cout << ans << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
