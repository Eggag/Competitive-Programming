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
	int n, m;
	cin >> n >> m;
	int a[n][m];
	ll sum = 0;
	rep(i, n) rep(j, m) cin >> a[i][j], sum += a[i][j];
	if(n <= 4 || m <= 4){
		cout << sum << endl;
		return 0;
	}
	vector<ll> mx(n, 0);
	rep(i, n){
		rep(j, m) mx[i] += a[i][j];
	}
	vector<ll> mx1(m, 0);
	rep(j, m){
		rep(i, n) mx1[j] += a[i][j];
	}
	//4 and 0
	ll ans = 0;
	vector<ll> mx2 = mx;
	sort(all(mx2));
	reverse(all(mx2));
	ll cur = 0;
	rep(i, min((int)mx2.size(), 4)){
		cur += mx2[i];
	}
	ans = max(cur, ans);
	mx2 = mx1;
	sort(all(mx2));
	reverse(all(mx2));
	cur = 0;
	rep(i, min((int)mx2.size(), 4)){
		cur += mx2[i];
	}
	ans = max(cur, ans);
	//3 and 1
	rep(j, m){
		//the 1 col
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		mx2 = mx;
		rep(i, mx2.size()){
			mx2[i] -= a[i][j];
			if(pq.size() < 3) pq.push(mx2[i]);
			else{
				if(mx2[i] > pq.top()){
					pq.pop(), pq.push(mx2[i]);	
				}
			}
		}
		ll cur = mx1[j];
		while(!pq.empty()) cur += pq.top(), pq.pop();
		ans = max(cur, ans);
	}
	rep(i, n){
		//the 1 row
		mx2 = mx1;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		rep(j, mx2.size()){
			mx2[j] -= a[i][j];
			if(pq.size() < 3) pq.push(mx2[j]);
			else{
				if(mx2[j] > pq.top()){
					pq.pop(), pq.push(mx2[j]);	
				}
			}
		}
		ll cur = mx[i];
		while(!pq.empty()) cur += pq.top(), pq.pop();
		ans = max(cur, ans);
	}
	//2 and 2
	if(m < n){
		rep(j, m) repn(j1, j + 1, m){
			priority_queue<ll, vector<ll>, greater<ll>> pq;
			mx2 = mx;
			rep(i, mx2.size()){
				mx2[i] -= (a[i][j] + a[i][j1]);
				if(pq.size() < 2) pq.push(mx2[i]);
				else{
					if(mx2[i] > pq.top()){
						pq.pop(), pq.push(mx2[i]);	
					}

				}
			}
			ll cur = mx1[j] + mx1[j1];
			while(!pq.empty()) cur += pq.top(), pq.pop();
			ans = max(cur, ans);
		}
	}
	else{
		rep(i, n) repn(i1, i + 1, n){
			mx2 = mx1;
			priority_queue<ll, vector<ll>, greater<ll>> pq;
			rep(j, mx2.size()){
				mx2[j] -= (a[i][j] + a[i1][j]);
				if(pq.size() < 2) pq.push(mx2[j]);
				else{
					if(mx2[j] > pq.top()){
						pq.pop(), pq.push(mx2[j]);	
					}
				}
			}
			ll cur = mx[i] + mx[i1];
			while(!pq.empty()) cur += pq.top(), pq.pop();
			ans = max(cur, ans);
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
