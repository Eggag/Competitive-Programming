#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis[2000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i], a[i]--;
	vi cur;
	int st = 0;
	int cnt = 0;
	while(!vis[st]){
		if(cnt == k){
			cout << st + 1 << endl;
			return 0;
		}
		vis[st] = 1;
		cur.pb(st);
		st = a[st];
		cnt++;
	}
	cur.pb(st);
	int nw = 0;
	rep(i, cur.size() - 1){
		if(cur[i] == cur[(int)cur.size() - 1]){
			nw = i;
			break;
		}
	}
	cur.pop_back();
	k -= nw;
	k %= (ll)(cur.size() - nw);
	cout << cur[nw + k] + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
