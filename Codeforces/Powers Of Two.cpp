#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi v;
	map<int, int> ans;
	queue<int> q;
	rep(i, 32){
		if(n & (1 << i)){
			v.pb((1 << i));
			if(i) q.push((1 << i));
			ans[1 << i]++;
		}
	}
	if(v.size() > k){
		cout << "NO" << endl;
		return 0;
	}
	if(v.size() == k){
		cout << "YES" << endl;
		rep(i, v.size()) cout << v[i] << " \n"[i == v.size() - 1];
		return 0;
	}
	int cnt = v.size();
	while(cnt < k && !q.empty()){
		int num = q.front(); q.pop();
		ans[num]--;
		ans[num / 2] += 2;
		if(num / 2 > 1){
			q.push(num / 2);
			q.push(num / 2);
		}
		cnt++;
	}
	if(cnt < k){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(auto x : ans){
		rep(i, x.se) cout << x.fi << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
