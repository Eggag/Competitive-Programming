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

struct cmp{
	bool operator()(const int a, const int b){
		return a > b;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		if(a[i] > (i + 1)){
			cout << -1 << endl;
			return 0;
		}
	}
	vi ans(n, -1), vis(n, 0);
	vi sn(n, 0), vs(n, 0);
	int prev = 0;
	rep(i, n){
		if(a[i] > prev) ans[i] = a[i] - (a[i] - prev), vis[i] = 1, sn[ans[i]] = 1;
		vs[a[i]] = 1;
		prev = a[i];
	}
	priority_queue<int, vi, cmp> q;
	rep(i, n) if(!sn[i] && !vs[i]) q.push(i);
	int mx = 1e6 - 10;
	rep(i, n){
		if(!vis[i]){
			if(!q.size()){
				if(i) ans[i] = ans[i - 1];
				else ans[i] = mx, mx--;
			}
			else{
				ans[i] = q.top();
				q.pop();
			}
		}
		if(vs[a[i]] && i < (n - 1) && a[i + 1] != a[i] && !sn[a[i]]) q.push(a[i]), vs[a[i]] = 0;
	}
	rep(i, n) cout << ans[i] << " ";
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

