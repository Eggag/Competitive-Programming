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
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0LL, sum1 = 0LL;
	rep(i, n) cin >> a[i], sum1 += a[i];
	map<ll, int> cnt, cnt1;
	rep(i, n) cnt1[a[i]]++;
	if((sum1 - sum) % 2 == 0 && cnt1[(sum1 - sum) / 2]){
		cout << "YES" << endl;
		return 0;
	}
	rep(i, n){
		sum += a[i];
		sum1 -= a[i];
		cnt[a[i]]++;
		if(sum1 > sum){
			if((sum1 - sum) % 2 == 0){
				ll dif = (sum1 - sum) / 2;
				if(cnt1[dif] > cnt[dif]){
					cout << "YES" << endl;
					return 0;
				}
			}
		}
		else if(sum1 < sum){
			ll dif = (sum - sum1) / 2;
			if(cnt[dif] && (sum - sum1) % 2 == 0){
				cout << "YES" << endl;
				return 0;
			}
		}
		else{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
