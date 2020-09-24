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

ll powt[18];

void solve(ll k){
	ll sum = 0;
	ll prev = 0;
	ll cnt = 1;
	ll num = 0;
	for(ll i = 1LL; i <= 17; i++){
		if(sum > k) break;
		ll tmp = powt[i] - powt[i - 1];
		ll now = sum + (num * (tmp)) + (i * ((tmp) * (tmp + 1))) / 2;
		num += (powt[i] - powt[i - 1]) * i;
		prev = sum;
		sum = now;
		cnt++;
	}
	if(sum > k) sum = prev, cnt--;
	if(sum == k){
		string ans = to_string(powt[cnt - 1] - 1);
		cout << ans[ans.size() - 1] << endl;
		return;
	}
	ll dif;
	cnt--;
	ll cur = (powt[cnt] - powt[cnt - 1]) * cnt;
	ll cnt1 = cnt - 1;
	while(cnt1 >= 0) cur += (powt[cnt1] - (cnt1 ? powt[cnt1 - 1] : 0)) * cnt1, cnt1--;
	cur += cnt + 1;
	ll sav = 0;
	while(sum < k){
		sav = sum;
		sum += cur;
		cur += cnt + 1;
	}
	dif = k - sav;
	ll key = 1;
	for(ll i = 1LL; i <= 17; i++){
		ll tmp = (powt[i] - powt[i - 1]) * i;
		if(tmp > dif) break;
		else dif -= tmp;
		key++;
	}
	ll base = powt[key - 1];
	ll div = (dif + key - 1) / key;
	base += div - 1;
	string s = to_string(base);
	if(!(dif % key)) cout << s[s.size() - 1] << endl;
	else cout << s[(dif % key) - 1] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	powt[0] = 1;
	for(ll i = 1LL; i <= 17; i++) powt[i] = powt[i - 1] * 10LL;
	int q;
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		solve(x);
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
