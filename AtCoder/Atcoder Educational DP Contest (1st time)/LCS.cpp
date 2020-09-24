#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	vector<vector<pair<int, pair<int, int>>>> dp(a.size() + 1,
		vector<pair<int, pair<int, int>>> (b.size() + 1, mp(-1, mp(0, 0))));
	dp[0][0] = {0, {0, 0}};
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			if(a[i] == b[j]){
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], mp(dp[i][j].f + 1, mp(i, j)));
			}
			dp[i + 1][j] = max(dp[i + 1][j], mp(dp[i][j].f, mp(i, j)));
			dp[i][j + 1] = max(dp[i][j + 1], mp(dp[i][j].f, mp(i, j)));
		}
	}
	pair<int, pair<int, int>> ans = mp(0, mp(0, 0));
	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			ans = max(ans, mp(dp[i][j].f, mp(i, j)));
		}
	}
	pi cur = ans.s;
	string answer = "";
	while(!(cur.f == 0 || cur.s == 0)){
		int i = cur.f;
		int j = cur.s;
		pi prev = dp[i][j].s;
		if(prev == mp(i - 1, j - 1)){
			answer += a[i - 1];
		}
		cur = prev;
	}
	reverse(all(answer));
	cout << answer << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
