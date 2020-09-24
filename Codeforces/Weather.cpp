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

int a[100005];
int pref[100005], suf[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] >= 0) pref[i] = pref[i - 1] + 1;
		else pref[i] = pref[i - 1];
	}
	for(int i = n; i >= 1; i--){
		if(a[i] <= 0) suf[i] = suf[i + 1] + 1;
		else suf[i] = suf[i + 1];
	}
	int ans = 1e9;
	for(int i = 1; i < n; i++) ans = min(ans, pref[i] + suf[i + 1]);
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
