#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll a[2 * n];
	ll sum1 = 0LL, sum = 0LL;
	rep(i, 2 * n) cin >> a[i], sum += a[i];
	sort(a, a + 2 * n);
	vi ans;
	rep(i, n){
		ans.pb(a[i]);
		sum1 += a[i];
	}
	repn(i, n, 2 * n) ans.pb(a[i]);
	if(sum % 2 == 0 && (sum / 2) == sum1) cout << "-1" << endl;
	else{
		rep(i, 2 * n){
			cout << a[i];
			if(i == 2 * n - 1) cout << endl;
			else cout << " ";
		}
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
