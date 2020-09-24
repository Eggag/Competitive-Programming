#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	freopen("teleport.in", "r", stdin);
        freopen("teleport.out", "w", stdout);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int d;
	d = min(abs(b - a), abs(x - a) + abs(y - b));
	d = min(d, abs(y - a) + abs(x - b));
	if(a == b){
		d = 0;
	}
	cout << d << endl;
	return 0;
}
