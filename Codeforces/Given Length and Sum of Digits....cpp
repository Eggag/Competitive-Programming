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

int m, s;

string solve(){
	if(m * 9 < s) return "-1 -1";
	if(s == 0) return ((m == 1) ? "0 0" : "-1 -1");
	int s1 = s;
	int s2 = s;
	string sm = "", l = "";
	repn(i, 1, m + 1){
		int c = max(s1 - 9 * (m - i), ((i == 1) ? 1 : 0));
		sm += c + '0';
		s1 -= c;
		int c1 = min(s2, 9);
		l += c1 + '0';
		s2 -= c1;
	}
	return sm + " " + l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> m >> s;
	cout << solve() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
