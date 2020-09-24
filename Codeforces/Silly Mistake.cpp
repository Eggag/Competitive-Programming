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

int vis[1000005];
int vis1[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(vis, 0, sizeof(vis));
	memset(vis1, 0, sizeof(vis1));
	vi ans;
	int cnt = 0;
	int act = 0;
	int last = 0;
	rep(i, n){
		if(a[i] > 0){
			if(!vis[a[i]]){
				if(vis1[a[i]] >= last) goto here;
				vis1[a[i]] = i + 1;
				vis[a[i]]++;
				act++;
				cnt++;
			}
			else{
here:;
				if(act){
					cout << -1 << endl;
					return 0;
				}
				ans.pb(cnt);
				vis[a[i]] = 1;
				vis1[a[i]] = i + 1;
				act = 1;
				cnt = 1;
				last = i + 1;
			}
		}
		else{
			if(!vis[-a[i]]){
				cout << -1 << endl;
				return 0;
			}
			cnt++;
			vis[-a[i]] = 0;
			act--;
			if(!act){
				ans.pb(cnt);
				cnt = 0;
				last = i + 1;
			}
		}
	}
	if(cnt){
		ans.pb(cnt);
		if(act){
			cout << -1 << endl;
			return 0;
		}
	}
	int st = 0;
	if(ans[0] == 0) st = 1;
	cout << ans.size() - st << endl;
	repn(i, st, ans.size()) cout << ans[i] << " ";
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
