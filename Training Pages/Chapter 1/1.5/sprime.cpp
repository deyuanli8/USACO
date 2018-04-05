/*
ID: eed7573
TASK: sprime
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

#define F0R(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define maxN 100000000
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi arr[8];
int n;
bool isPrime(int a) {
	if (a == 2) {
		return true;
	}
	if (a % 2 == 0) return false;
	for (int i = 3; SQ(i) <= a; i += 2) {
		if (a % i == 0) return false;
	}
	return true;
}
int main() {
	FAST
	ofstream cout("sprime.out");
	ifstream cin("sprime.in");
	cin >> n;
	arr[0].PB(2);
	arr[0].PB(3);
	arr[0].PB(5);
	arr[0].PB(7);
	for (int i = 1; i < n; i++) {
		for (int a : arr[i - 1]) {
			for (int j = 1; j <= 9; j += 2) {
				if (isPrime(10*a+j)) {
					arr[i].PB(10 * a + j);
				}
			}
		}
		arr[i - 1].clear();
	}
	sort(arr[n - 1].begin(), arr[n - 1].end());
	for (int a : arr[n - 1]) {
		cout << a << endl;
	}
	return 0;
}
