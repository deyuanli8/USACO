/*
ID: eed7573
TASK: runround
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

ull m;
bool checkRun(string a) {
	bool arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	bool nums[10] = { 0,0,0,0,0,0,0,0,0,0 };
	FOR(i, a.length()) {
		if (nums[a[i] - '0']) return false;
		nums[a[i] - '0'] = true;
	}
	int i = 0;
	FOR(j, a.length()) {
		if (arr[i]) return false;
		arr[i] = true;
		i = (i + a[i] - '0') % a.length();
	}
	return i==0;
}
int main() {
	FAST
	ofstream cout("runround.out");
	ifstream cin("runround.in");
	cin >> m;
	for (ull i = m + 1; i < 1000000000; i++) {
		if (checkRun(to_string(i))) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
