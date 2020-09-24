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
	int n, m;
	cin >> n >> m;
	vi t(n);
	rep(i, n) cin >> t[i];
	vi sum(n + 1, 0);
	//maintain a sorted array
	vi cur;
	int prev = 0;
	rep(i, n){
		int cnt = t[i] + prev;
		int mn = 0;
		sort(all(cur));
		reverse(all(cur));
		int j = 0;
		int cur1 = cnt;
		while(cur1 > m && j < cur.size()){
			cur1 -= cur[j];
			mn++;
			j++;
		}
		prev = cnt;
		cur.pb(t[i]);
		cout << mn << " \n"[i == n - 1];
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
