/*
ID: eed7573
TASK: preface
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
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
#define endl "\n"

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

int n;
int arr[7];
int num[7] = { 1,5,10,50,100,500,1000 };
char numerals[7] = { 'I','V', 'X', 'L', 'C', 'D', 'M' };
void calculate(int a, int index) {
	if (a == 0 || index == -1) return;
	if (index == 1 && a == 9) {
		arr[2] += 1;
		arr[0] += 1;
		return;
	}
	if (index == 3 && a >= 90) {
		arr[2] += 1;
		arr[4] += 1;
		calculate(a - 90, index - 1);
		return;
	}
	if (index == 5 && a >= 900) {
		arr[4] += 1;
		arr[6] += 1;
		calculate(a - 900, index - 1);
		return;
	}
	if (a / num[index] <= 3) {
		arr[index] += a / num[index];
		calculate(a - num[index] * (a / num[index]), index - 1);
		return;
	}
	arr[index] += 1;
	arr[index + 1] += 1;
	calculate(a - num[index] * 4, index - 1);
}
int main() {
	FAST
	ofstream cout("preface.out");
	ifstream cin("preface.in");
	cin >> n;
	F0R(i, 1, n + 1) {
		calculate(i, 6);
	}
	FOR(i, 7) {
		if (arr[i] == 0) break;
		cout << numerals[i] << " " << arr[i] << endl;
	}
	return 0;
}
