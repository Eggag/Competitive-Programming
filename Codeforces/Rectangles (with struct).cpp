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

struct rect{
	int x1, y1, x2, y2;
};

rect cross(rect x, rect y){
	rect ret;
	ret.x1 = max(y.x1, x.x1);
	ret.y1 = max(y.y1, x.y1);
	ret.x2 = min(y.x2, x.x2);
	ret.y2 = min(y.y2, x.y2);
	return ret;
}

bool valid(rect x){
	return ((x.x1 <= x.x2) && (x.y1 <= x.y2));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<rect> a(n);
	rep(i, n){
		int b, c, d, e;
		cin >> b >> c >> d >> e;
		a[i] = {b, c, d, e};
	}
	vector<rect> pref(n), suf(n);
	rep(i, n){
		if(!i) pref[i] = a[i];
		else pref[i] = cross(a[i], pref[i - 1]);
	}
	suf[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--){
		suf[i] = cross(a[i], suf[i + 1]);
	}
	repn(i, 1, n - 1){
		rect cur = cross(pref[i - 1], suf[i + 1]);
		if(valid(cur)){
			cout << cur.x1 << " " << cur.y1 << endl;
			return 0;
		}
	}
	if(valid(suf[1])){
		cout << suf[1].x1 << " " << suf[1].y1 << endl;
		return 0;
	}
	if(valid(pref[n - 2])){
		cout << pref[n - 2].x1 << " " << pref[n - 2].y1 << endl;
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
