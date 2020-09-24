#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(n);
	ll sum = 0;
	int mx = 0;
	rep(i, n) cin >> a[i], sum += a[i], mx = max(mx, a[i]);
	if(n == 1 || mx == 1){
		cout << 0 << endl;
		return 0;
	}
	sort(all(a));
	reverse(all(a));
	int req = 1;
	int cur = a[0] - 1; //the highest -1
	int ind = 0;
	while(ind < n){
		if(ind < (n - 1) && cur > 1){ //can move on
			if(a[ind + 1] >= cur) ind++, req++, cur--;
			else{
				req += cur - a[ind + 1];
				cur = a[ind + 1];
			} 
		}
		else{ //we are on the last one
			if(ind == n - 1){
				req += cur;
				break;
			}
			if(cur == 1){
				req += n - ind - 1;
				break;
			}
		}
	}
	cout << sum - req << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
