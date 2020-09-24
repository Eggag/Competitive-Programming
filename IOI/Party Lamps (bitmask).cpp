#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int n, c;
int state[105];
vi on, off;
set<string> ans;

void test(int cur){
	repn(i, 1, n + 1) state[i] = 1;
	int cc = 0;
	rep(i, 4) if(cur & (1 << i)) cc++;
	if(cc > c || (c - cc) % 2 != 0) return;
	if(cur & 1) repn(i, 1, n + 1) state[i] = 1 - state[i];
	if(cur & 2) repn(i, 1, n + 1) if(i % 2 == 1) state[i] = 1 - state[i];
	if(cur & 4) repn(i, 1, n + 1) if(i % 2 == 0) state[i] = 1 - state[i];
	if(cur & 8) repn(i, 1, n + 1) if(i % 3 == 1) state[i] = 1 - state[i];
	for(int l : on) if(!state[l]) return;
	for(int l : off) if(state[l]) return;
	string ret = "";
	repn(i, 1, n + 1) ret += state[i] + '0';
	ans.insert(ret);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> c;
	while(1){
		int x;
		cin >> x;
		if(x == -1) break;
		on.pb(x);
	}
	while(1){
		int x;
		cin >> x;
		if(x == -1) break;
		off.pb(x);
	}
	rep(i, 16) test(i);
	if(!ans.size()){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(string s : ans){
		cout << s << endl;
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
