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

int dp[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
     	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + (s1[i - 1] != s2[i - 1]);
		if(i >= 2 && s1[i - 1] == s2[i - 2] && s1[i - 2] == s2[i - 1]) dp[i] = min(dp[i], dp[i - 2] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
