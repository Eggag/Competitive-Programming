#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

bool q(int a, int b){
	cout << 1 << " " << a << " " << b << endl;
	string s;
	cin >> s;
	return (s == "TAK" ? 1 : 0);
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if(n == 2){
		cout << "2 1 2" << endl;
		return 0;
	}
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		bool f = q(mid, mid + 1);
		if(f) r = mid;
		else l = mid + 1;
	}
	int l1 = 1, r1 = l - 1;
	while(l1 < r1){
		int mid = (l1 + r1) / 2;
		bool f = q(mid, mid + 1);
		if(f) r1 = mid;
		else l1 = mid + 1;
	}
	int l2 = l + 1, r2 = n;
	while(l2 < r2){
		int mid = (l2 + r2) / 2;
		bool f = q(mid, mid + 1);
		if(f) r2 = mid;
		else l2 = mid + 1;
	}
	if(l == 1) cout << 2 << " " << l << " " << l2 << endl;
	else{
		int a = l1;
		if(!q(l1, l)) a = l2;
		cout << 2 << " " << l << " " << a << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
