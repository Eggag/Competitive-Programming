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

int a[10][10];
int dp[10][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	while(q--){
		char c[10], b[10];
		cin >> c >> b;
		a[b[0] - 'a'][c[0] - 'a']++;
	}
	dp[1][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 6; k++){
				dp[i + 1][k] += dp[i][j] * a[j][k];
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < 6; i++){
		sum += dp[n][i];
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
