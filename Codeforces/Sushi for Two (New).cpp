#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi s(n);
	rep(i, n) cin >> s[i];
	int ans = 2;
	//store the current block and compafre it to prev
	//when done make prev = cur, ans = min(ans, min(cur, prev) * 2)
	int cur = 1;
	int prev = 1;
	repn(i, 1, n){
		if(s[i] == s[i - 1]){
			cur++;
		}
		else{
			ans = max(ans, min(cur, prev) * 2);
			prev = cur;
			cur = 1;
		}
	}
	cout << max(ans, min(cur, prev) * 2) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
