#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[mxN], num[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi b(n);
	rep(i, n) cin >> b[i];
	int ans = n;
	for(int i = 2; (i * i) <= n; i++){
		int len = sq(i);
		memset(cnt, 0, sizeof(cnt));
		memset(num, 0, sizeof(num));
		rep(j, len){
			if(cnt[b[j]]) num[cnt[b[j]]]--;
			cnt[b[j]]++;
			num[cnt[b[j]]]++;
		}
		if(num[i] == i) ans++;
		repn(j, len, n){
			//add
			if(cnt[b[j]]) num[cnt[b[j]]]--;
			cnt[b[j]]++;
			num[cnt[b[j]]]++;
			//sub
			num[cnt[b[j - len]]]--;
			cnt[b[j - len]]--;
			num[cnt[b[j - len]]]++;
			if(num[i] == i) ans++;
		}
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
