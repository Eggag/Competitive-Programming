#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int a, b, c, d;
	char f;
	cin >> a >> f >> b;
	cin >> c >> f >> d;
	int m1 = a * 60 + b;
	int m2 = c * 60 + d;
	int l = (m1 + m2) / 2;
	int r = l % 60;
	l = l / 60;
	if(l < 10) cout << "0";
	cout << l << ":";
	if(r < 10) cout << "0";
	cout << r << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
