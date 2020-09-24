#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int k, n, w;
	cin >> k >> n >> w;
	int sum = 0;
	for(int i = 1; i <= w; i++){
		sum += i * k;
	}
	cout << max(0, sum - n) << endl;
	return 0;	
}
