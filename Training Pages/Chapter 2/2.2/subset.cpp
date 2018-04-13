/*
ID: eed7573
TASK: subset
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
int arr[40][40 * 40];
int main() {
	FAST
	ofstream cout("subset.out");
	ifstream cin("subset.in");
	cin >> n;
	arr[0][1] = 1;
	F0R(i, 1, n) {
		FOR(j, (i+1)*(i+2)/2+1) {
			if (j + i + 1 <= n * n - 1) {
				arr[i][j] += arr[i - 1][j + i + 1];
			}
			if (j == 0) continue;
			arr[i][j] += arr[i - 1][abs(j - i - 1)];
			if (j == i + 1) {
				arr[i][j] += arr[i - 1][abs(j - i - 1)];
			}
		}
	}
	cout << arr[n - 1][0] << endl;
	return 0;
}
