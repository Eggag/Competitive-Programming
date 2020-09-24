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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int f = (int)stoi(s.substr(0, 2));
	int f1 = (int)stoi(s.substr(2, 2));
	int fl = 0, fl1 = 0, fl2 = 0, fl3 = 0;
	if(f < 13 && f > 0) fl = 1;
	if(f < 99 && f >= 0) fl1 = 1;
	if(f1 < 13 && f1 > 0) fl2 = 1;
	if(f1 < 99 && f1 >= 0) fl3 = 1;
	if(fl && fl1 && fl2 && fl3) cout << "AMBIGUOUS" << endl;
	else if(fl && fl3) cout << "MMYY" << endl;
	else if(fl1 && fl2) cout << "YYMM" << endl;
	else cout << "NA" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
