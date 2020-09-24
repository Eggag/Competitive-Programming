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

int cnt[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int N = s.length();
	rep(i, N) cnt[i + 1] = cnt[i] + ((s[i] <= 'Z' && s[i] >= 'A') ? 1 : 0);
	int ans = N;
	rep(i, N + 1){
		int llow = i - cnt[i];
		int rup = cnt[N] - cnt[i];
		ans = min(ans, rup + llow);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
