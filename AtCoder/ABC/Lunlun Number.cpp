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

vector<string> tot;

void dfs(string cur, int des, int ln){
	if(tot.size() == 100000) return;
	if(des == ln){
		tot.pb(cur);
		return;
	}
	if(cur[cur.size() - 1] > '0'){
		string cur1 = cur;
		char add = cur[cur.size() - 1];
		add--;
		cur1 += add;
		dfs(cur1, des, ln + 1);
	}
	string cur1 = cur;
	char add = cur[cur.size() - 1];
	cur1 += add;
	dfs(cur1, des, ln + 1);
	if(cur[cur.size() - 1] < '9'){
		string cur1 = cur;
		char add = cur[cur.size() - 1];
		add++;
		cur1 += add;
		dfs(cur1, des, ln + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k;
	cin >> k;
	if(k < 10){
		cout << k << endl; //digits
		return 0;
	}
	rep(i, 9) tot.pb(to_string(i + 1));
	repn(len, 2, 11){
		//the length of the string
		for(char st = '1'; st <= '9'; st++){
			string go = "";
			go += st;
			dfs(go, len, 1);
		}
	}
	cout << tot[k - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
