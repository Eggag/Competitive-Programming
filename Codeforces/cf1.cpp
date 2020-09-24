#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, a, w, l;
	cin >> n >> m >> a;
	l = n / a + 1;
	w = m / a + 1;
	if(m % a == 0){
		w--;
	}
	if(n % a == 0){
		l--;
	}
	cout << l * w << endl;
	return 0;
}
	

