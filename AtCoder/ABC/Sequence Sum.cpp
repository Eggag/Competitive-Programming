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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, x, m;
	cin >> n >> x >> m;
	ll cur = x;
	map<int, int> vis;
	vis[cur] = 1;
	int lst = -1, rd = -1;
	repn(i, 2, min(n + 3, m + 3)){
		cur = sq(cur);
		cur %= m;
		if(vis[cur]){
			lst = cur;
			rd = i - 1;
			break;
		}
		if(!vis[cur]) vis[cur] = i;
	}
	if(rd == -1){
		//means we just sum it up - no cycle because n is too small
		cur = x;
		ll tot = 0LL;
		repn(i, 1, n + 1){
			if(i != 1) cur = sq(cur) % m;
			tot += cur;
		}
		cout << tot << endl;
		return 0;
	}
	ll sum = 0LL;
	cur = x;
	repn(i, 1, vis[lst]){
		if(i == 1) sum += x;
		else{
			cur = sq(cur) % m;
			sum += cur;
		}
	}
	ll cyc = 0LL;
	repn(j, vis[lst], rd + 1){
		if(j == 1) cyc += x;
		else{
			cur = sq(cur) % m;
			cyc += cur;
		}
	}
	ll rem = n - vis[lst] + 1;
	sum += cyc * (rem / (rd - vis[lst] + 1));
	rem %= (rd - vis[lst] + 1);
	rep(i, rem){
		cur = sq(cur) % m;
		sum += cur;
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
