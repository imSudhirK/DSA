#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
	ifstream intxt, outtxt;
	intxt.open("in.txt");
	outtxt.open("out.txt");
	int n;
	intxt >> n;
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	int *d = new int[n];
	for (int i = 0; i < n; i++)
		intxt >> a[i];
	for (int i = 0; i < n; i++)
		intxt >> b[i];
	for (int i = 0; i < n; i++)
		intxt >> c[i];
	for (int i = 0; i < n; i++)
		intxt >> d[i];
	bool bx = true;
	int fin1[n], fin2[n];
	if (outtxt.peek() == 'i') {
		bx= false;
	}
	else {
		for (int i = 0; i < n; i++){
			outtxt >> fin1[i];
			fin1[i]--;
		}
		for (int i = 0; i < n; i++){
			outtxt >> fin2[i];
			fin2[i]--;
		}		
	}
	bool x = true;
	for (int i = 0; i < n; i++) {
		if (b[fin1[i]] < d[fin2[i]]) {
			x = false;
			cout << i << ' ' << b[fin1[i]] << ' ' << d[fin2[i]] << endl;
		}
		if (i) {
			if (a[fin1[i-1]] > a[fin1[i]] || c[fin2[i-1]] > c[fin2[i]]){
				x = false;
				cout << i << endl;
				cout << a[fin1[i-1]] << ' ' << a[fin1[i]] << endl;
				cout << c[fin2[i-1]] << ' ' << c[fin2[i]] << endl;
			}
		}
	}
	cout << (x? "CORRECT\n" : "WRONG\n");
	return 0;
}