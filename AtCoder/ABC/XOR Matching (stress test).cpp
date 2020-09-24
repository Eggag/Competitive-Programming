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

void verify(deque<int> ans, int k, int m){
	vi a;
	for(int x : ans) a.pb(x);
	int n = a.size();
	rep(i, n) repn(j, i + 1, n){
		if(a[i] == a[j]){
			int x = 0;
			repn(k, i + 1, j) x ^= a[k];
			if(k != x){
				cout << "Wrong Answer" << endl;
				exit(0);
			}
		}
	}
	cout << "Accepted" << endl;
}

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

void solve(int m, int k){
	if(k >= ((1 << m) - 1)){
		return;
	}
	if(!k){
		return;
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
		//cout << -1 << endl;
		return;
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
		verify(ans, k, m);
		//for(int x : ans) cout << x << " ";
		//cout << endl;
	}
}

int main(){
	while(true){
		int n = rng() % 3, k = rng() % 10;
		solve(n, k);
	}
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
