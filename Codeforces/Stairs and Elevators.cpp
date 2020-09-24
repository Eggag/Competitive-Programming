#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int c[100005];
int e[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, st, el, v;
	cin >> n >> m >> st >> el >> v;
	rep(i, st) cin >> c[i];
	rep(i, el) cin >> e[i];
	int q;
	cin >> q;
	rep(i, q){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2){
			cout << abs(y1 - y2) << endl;
			continue;
		}
		int ans = 1e9;
		if(x1 > x2) swap(x1, x2), swap(y1, y2);
		if(st){
			auto ls = lower_bound(c, c+ st, y1);
			if(ls != c + st){
				int ls1 = ls - c;
				ans = min(abs(c[ls1] - y1) + abs(c[ls1] - y2) + (x2 - x1), ans);
			}
			int ls2;
			if(ls == c + st){
				ls2 = st - 1;
				ans = min(ans, abs(c[ls2] - y1) + abs(c[ls2] - y2) + (x2 - x1));
			}
			else{
				if((ls - c - 1) >= 0){
					ls2 = ls - c - 1;
					ans = min(ans, abs(c[ls2] - y1) + abs(c[ls2] - y2) + (x2 - x1));
				}
			}
		}
		if(el){
			auto le = lower_bound(e, e + el, y1);
			if(le != e + el){
				int le1 = le - e;
				int tmp = (x2 - x1) / v;
				if((x2 - x1) % v != 0) tmp++;
				ans = min(abs(e[le1] - y1) + abs(e[le1] - y2) + tmp, ans);
			}
			int le2, tmp1;
			if(le == e + el){
				le2 = el - 1;
				tmp1 = (x2 - x1) / v;
				if((x2 - x1) % v != 0) tmp1++;
				ans = min(ans, abs(e[le2] - y1) + abs(e[le2] - y2) + tmp1);
			}
			else{
				if((le - e - 1) >= 0){
					le2 = le - e - 1;
					tmp1 = (x2 - x1) / v;
				        if((x2 - x1) % v != 0) tmp1++;
					ans = min(ans, abs(e[le2] - y1) + abs(e[le2] - y2) + tmp1);
				}
			}
		}
		cout << ans << endl;
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

