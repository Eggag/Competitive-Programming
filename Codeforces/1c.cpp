#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long a[n], b[n/2];
	for(int i = 0; i < n/2; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	for(int i = 0; i < n/2; i++){
		if(i == 0){
			a[0] = 0;
			a[n - 1] = b[0];
		}
		else{
			a[i] = a[i - 1] + max(0LL, b[i] - b[i - 1]);
			a[n - 1 - i] = b[i] - a[i];
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
