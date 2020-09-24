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
const ld eps = 1e-9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k, nm;
ld l, v1, v2;

bool check(ld g){
	ld cur = 0.0, pos = 0.0;
	rep(i, nm){
		if((pos + (((l - pos) / v2) * v1) + eps) >= l){
			ld l1 = 0.0, r = 1.1e9;
			rep(j, 60){
				ld mid = (l1 + r) / 2;
				if((pos + (v1 * mid) + eps) > l) r = mid;
				else l1 = mid;
			}
			cur += l1;
			if((cur + eps) <= g) return 1;
			else return 0;
		}
		ld pos1 = 0.0;
		if(i == (nm - 1)) pos1 = l; //just get it to the end
		else{
			ld l2 = pos, r2 = l;	
			int f = 0;
			rep(j, 60){
				ld mid = (l2 + r2) / 2;
				if((cur + ((mid - pos) / v2) + ((l - mid) / v1) - eps) <= g){
					r2 = mid;
					f = 1;
				}
				else l2 = mid;
			}
			if(!f) return 0;
			pos1 = l2;
		}
		cur += (pos1 - pos) / v2; //the time it takes for the bus to get there
		if(i == (nm - 1)){ //that was the last batch
			if((cur - eps) <= g) return 1;
			else return 0;
		}
		pos += ((pos1 - pos) / v2) * v1;
		ld l1 = 0.0, r = 1.1e9;
		ld dist = pos1 - pos;
		rep(j, 60){
			ld mid = (l1 + r) / 2;
			if(((mid * v1) + (mid * v2) + eps) > dist) r = mid;
			else l1 = mid;
		}
		pos += v1 * l1;
		cur += l1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> l >> v1 >> v2 >> k;
	nm = (n + k - 1) / k;
	cout << fixed << setprecision(10);
	ld l1 = 0.0, r = 1.1e9;
	while(abs(r - l1) > 1e-7){
		ld mid = (l1 + r) / 2;
		if(check(mid)) r = mid;
		else l1 = mid;
	}
	cout << l1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
