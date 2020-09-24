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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	pair<int, pi> dp[a.size() + 1][b.size()+ 1];
        for(int i = 0; i <= a.size(); i++){
                for(int j = 0; j <= b.size(); j++){
                        dp[i][j] = {-1, {0, 0}};
                }
        }
        dp[0][0] = {0, {0, 0}};
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			if(a[i] == b[j]){
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], mp(dp[i][j].fi + 1, mp(i, j)));
			}
			dp[i][j + 1] = max(dp[i][j + 1], mp(dp[i][j].fi, mp(i, j)));
			dp[i + 1][j] = max(dp[i + 1][j], mp(dp[i][j].fi, mp(i, j)));
		}
	}
	pair<int, pi> ans = mp(0, mp(0, 0));
	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			ans = max(ans, mp(dp[i][j].fi, mp(i, j)));
		}
	}
	pi cur = ans.se;
	string answer = "";
	while(!(cur.fi == 0 && cur.se == 0)){
		int i = cur.fi;
		int j = cur.se;
		pi prev = dp[i][j].se;
		if(prev == mp(i - 1, j - 1)){
			answer += a[i - 1];
		}
		cur = prev;
	}
	if(answer.size() == 0) answer = " ";
	reverse(all(answer));
	cout << answer << endl;
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
