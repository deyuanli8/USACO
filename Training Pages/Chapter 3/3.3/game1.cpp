/*
ID: eed7573
TASK: game1
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
typedef vector<pii> vp;

int n;
int nums[100];
int arr[100][100];
int s = 0;
int main() {
	FAST
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	cin >> n;
	FOR(i, n) {
		cin >> nums[i];
		s += nums[i];
	}
	FOR(i, n) {
		arr[i][i] = nums[i];
	}
	F0R(i, 1, n) {
		FOR(j, n - i) {
			if (i % 2 == 0) {
				arr[j][j + i] = max(nums[j + i] + arr[j][j + i - 1], nums[j] + arr[j + 1][j + i]);
			}
			else {
				arr[j][j + i] = min(arr[j][j + i - 1], arr[j + 1][j + i]);
			}
		}
	}
	if (n % 2 == 0) {
		cout << s - arr[0][n - 1] << " " << arr[0][n - 1] << "\n";
	}
	else {
		cout << arr[0][n - 1] << " " << s - arr[0][n - 1] << "\n";
	}
	return 0;
}
