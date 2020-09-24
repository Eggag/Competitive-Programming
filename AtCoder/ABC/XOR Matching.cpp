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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int m, k;
	cin >> m >> k;
	if(!k){
		rep(i, (1 << m)) cout << i << " " << i << " ";
		cout << endl;
		return 0;
	}
	deque<int> ans;
	int f = 0;
	map<int, int> vis;
	pi gd;
	rep(i, (1 << m)){
		int j = k ^ i;
		if(j >= 0 && j < (1 << m) && i != k && j != k && i != j){
			ans.pb(i);
			ans.pb(j);
			vis[i] = 1;
			vis[j] = 1;
			vis[k] = 1;
			ans.push_front(k);
			ans.pb(k);
			f = 1;
			gd = mp(i, j);
			break;
		}
	}
	//for(int x : ans) cout << x << " ";
	//cout << endl;
	if(!f){
		cout << -1 << endl;
		return 0;
	}
	else{
		rep(i, (1 << m)){
			if(!vis[i]){
				ans.push_front(i);
				ans.pb(i);
			}
		}
		ans.pb(gd.se);
		ans.push_front(gd.fi);
		//verify(ans, k, m);
		for(int x : ans) cout << x << " ";
		cout << endl;
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
