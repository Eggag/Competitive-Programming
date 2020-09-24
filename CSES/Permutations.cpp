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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(n <= 3){
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	deque<int> q;
	q.pb(2);
	q.pb(4);
	q.pb(1);
	q.pb(3);
	int cur = 5;
	int turn = 0;
	while(n > 4){
		if(turn % 2 == 0) q.pb(cur);
		else q.push_front(cur);
		cur++;
		turn++;
		n--;
	}
	for(auto x : q){
		cout << x << " ";
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
