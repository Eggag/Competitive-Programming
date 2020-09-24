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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 1e9;
	vi cntJ(n, 0), cntO(n, 0), cntI(n, 0);
	cntJ[0] = (s[0] == 'J');
	repn(i, 1, n) cntJ[i] = cntJ[i - 1] + (s[i] == 'J');
	cntO[0] = (s[0] == 'O');
	repn(i, 1, n) cntO[i] = cntO[i - 1] + (s[i] == 'O');
	cntI[0] = (s[0] == 'I');
	repn(i, 1, n) cntI[i] = cntI[i - 1] + (s[i] == 'I');
	rep(i, n - (3 * k) + 1) if(s[i] == 'J'){
		int l = i, r = n - 1;
		int num = 0;
		if(i) num = cntJ[i - 1];
		while(l < r){
			int mid = (l + r) / 2;
			if((cntJ[mid] - num) >= k) r = mid;
			else l = mid + 1;
		}
		if((cntJ[l] - num) < k) continue;
		int cur = (l - i + 1) - k;
		num = cntO[l];
		int l1 = l + 1, r1 = n - 1;
		while(l1 < r1){
			int mid = (l1 + r1) / 2;
			if((cntO[mid] - num) >= k) r1 = mid;
			else l1 = mid + 1;
		}
		if((cntO[l1] - num) < k) continue;
		cur += (l1 - l) - k;
		num = cntI[l1];
		int l2 = l1 + 1, r2 = n - 1;
		while(l2 < r2){
			int mid = (l2 + r2) / 2;
			if((cntI[mid] - num) >= k) r2 = mid;
			else l2 = mid + 1;
		}
		if((cntI[l2] - num) < k) continue;
		cur += (l2 - l1) - k;
		ans = min(ans, cur);
	}
	if(ans == 1e9) ans = -1;
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
