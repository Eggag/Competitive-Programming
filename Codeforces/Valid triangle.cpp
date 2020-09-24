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
	int a, b, c;
	cin >> a >> b >> c;
	int s = a + b + c;
	if(a + b > c && a + c > b && c + b > a){
		cout << 0 << endl;
		return 0;
	}
	int mx = max(a, b);
	mx = max(mx, c);
	cout << (mx + mx + 1) - s << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
