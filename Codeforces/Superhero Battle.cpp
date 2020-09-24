#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#ifdef LOCAL
clock_t t = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll num;
	int n;
	cin >> num >> n;
	ll h = num;
	vi a;
	ll sum = 0;
	ll diff = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.pb(x);
		h += x;
		sum -= x;
		if(h <= 0){
			cout << i + 1 << endl;
			return 0;
		}
		diff = max(diff, sum);
	}
	if(sum <= 0){
		cout << "-1" << endl;
		return 0;
	}
	ll b = (num - diff) / sum;
	num -= b * sum;
	ll ans = b * n;
	for(int i = 0;; i++){
		num += a[i % n];
		ans++;
		if(num <= 0){
			cout << ans << endl;
			return 0;
		}
	}
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
