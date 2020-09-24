#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long xx = 0;
	long long yy = 0;
	for(int i = 0; i < (2 * n); i++){
		long long x, y;
		cin >> x >> y;
		xx += x;
		yy += y;
	}
	cout << xx/n << " " << yy/n << endl;
	return 0;
}
