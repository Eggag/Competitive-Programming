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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	//weird constraints lol
	vector<ll> x1(n), y1(n), x2(n), y2(n);
	rep(i, n){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	//so 1 is either included or not
	//so we just check those two cases
	//include 1
	ll up = 1.1e10, down = -1.1e10, left = -1.1e10, right = 1.1e10;	
	int cnt = 0;
	rep(i, n){
		if((x1[i] > right) || (x2[i] < left) || (y1[i] > up) || (y2[i] < down)){
			//exclude it
			cnt++;
			continue;
		}
		up = min(up, y2[i]);
		down = max(down, y1[i]);
		left = max(left, x1[i]);
		right = min(right, x2[i]);
	}
	if(cnt <= 1){
		cout << right << " " << up << endl;
		return 0;
	}
	up = 1.1e10, down = -1.1e10, left = -1.1e10, right = 1.1e10;	
	//exclude the 1
	repn(i, 1, n){
		up = min(up, y2[i]);
		down = max(down, y1[i]);
		left = max(left, x1[i]);
		right = min(right, x2[i]);
	}
	if(up >= down && right >= left){
		cout << right << " " << up << endl;
		return 0;
	}
	up = 1.1e10, down = -1.1e10, left = -1.1e10, right = 1.1e10;	
	cnt = 0;
	for(int i = n - 1; i >= 0; i--){
		if((x1[i] > right) || (x2[i] < left) || (y1[i] > up) || (y2[i] < down)){
			//exclude it
			cnt++;
			continue;
		}
		up = min(up, y2[i]);
		down = max(down, y1[i]);
		left = max(left, x1[i]);
		right = min(right, x2[i]);
	}
	if(cnt <= 1){
		cout << right << " " << up << endl;
		return 0;
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
