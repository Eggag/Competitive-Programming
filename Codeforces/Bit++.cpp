#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int x = 0;
	for(int i = 0; i < n; i++){
		string operation;
		cin >> operation;
		if(operation == "X++" || operation == "++X"){
			x++;
		}
		else{
			x--;
		}
	}
	cout << x << endl;
	return 0;
}
