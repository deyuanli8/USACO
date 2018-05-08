/*
ID: eed7573
TASK: fracdec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SQ(a) (a)*(a)

#define F0R(i, a, b) for (int i=(a); i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define maxD 100000
int n, d;
int arr[maxD];
bool rep[maxD];
int main() {
	FAST
		ofstream fout("fracdec.out");
	ifstream fin("fracdec.in");
	fin >> n >> d;
	fout << n / d << ".";
	int curS = 1 + to_string(n / d).length();
	int counter = 0;
	n = n % d;
	if (n == 0) {
		fout << 0 << endl;
		return 0;
	}
	string s = "";
	while (n != 0 && !rep[n]) {
		arr[n] = counter;
		rep[n] = true;
		counter++;
		s += to_string(n * 10 / d);
		n = (10 * n) % d;
	}
	if (n == 0) {
		FOR(i, counter) {
			if ((curS + i) % 76 == 0) fout << "\n";
			fout << s[i];
		}
	}
	else {
		bool par = false;
		FOR(i, counter) {
			if (((curS + i + 1) % 76 == 0 && par) || ((curS + i) % 76 == 0 && !par)) fout << "\n";
			if (i == arr[n]) {
				par = true;
				fout << "(";
			}
			fout << s[i];
		}
		fout << ")";
	}
	fout << "\n";
	return 0;
}
