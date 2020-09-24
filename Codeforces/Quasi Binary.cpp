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

vi num;
int dp[1000005];
int p[1000005];

bool good(int x){
	while(x){
		if(!(x % 10 == 0 || x % 10 == 1)) return false;
		x /= 10;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1){
		if(good(i)) num.pb(i);
	}
	repn(i, 1, n + 1){
		dp[i] = 1e9;
	}
	dp[0] = 0;
	repn(i, 1, n + 1){
		for(int j : num){
			if(i - j >= 0 && dp[i - j] < dp[i]){
				dp[i] = dp[i - j] + 1;
				p[i] = j;
			}
		}
	}
	vi ans;
	int s = n;
	while(s){
		ans.pb(p[s]);
		s -= p[s];
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
