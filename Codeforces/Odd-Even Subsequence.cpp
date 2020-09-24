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

int n, k;
int a[200005];

bool check(int mx){
	vi p;
	rep(i, n) if(a[i] <= mx && i) p.pb(i);
	if(p.size()){
		int t = (p.size() > 0);
		int lst = p[0];
		repn(i, 1, p.size()) if(p[i] - lst > 1) lst = p[i], t++;
		if(t >= k / 2) return 1;
	}
	p.clear();
	rep(i, n) if(a[i] <= mx && i < (n - 1)) p.pb(i);
	if(p.size()){
		int t = (p.size() > 0);
		int lst = p[0];
		repn(i, 1, p.size()) if(p[i] - lst > 1) lst = p[i], t++;
		if(t >= k / 2) return 1;
	}
	return 0;
}

bool check1(int mx){
	vi p;
	rep(i, n) if(a[i] <= mx && i && i < (n - 1)) p.pb(i);
	if(p.size()){
		int t = (p.size() > 0);
		int lst = p[0];
		repn(i, 1, p.size()) if(p[i] - lst > 1) lst = p[i], t++;
		if(t >= k / 2) return 1;
	}
	p.clear();
	rep(i, n) if(a[i] <= mx) p.pb(i);
	if(p.size()){
		int t = (p.size() > 0);
		int lst = p[0];
		repn(i, 1, p.size()) if(p[i] - lst > 1) lst = p[i], t++;
		if(t >= (k / 2) + 1) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	if(k % 2 == 0){
		int l = 0, r = 1e9 + 10;
		while(l < r){
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	else{
		//we need to do 2 checks now
		int l = 0, r = 1e9 + 10;
		while(l < r){
			int mid = (l + r) / 2;
			if(check1(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
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
