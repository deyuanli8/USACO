/*
ID: eed7573
TASK: numtri
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
#define maxR 1000

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int arr[maxR][maxR];
int nums[maxR][maxR];
int r;
int main() {
	FAST
	ofstream cout("numtri.out");
	ifstream cin("numtri.in");
	cin >> r;
	int next;
	FOR(i, r) {
		FOR(j, i + 1) {
			cin >> next;
			nums[i][j] = next;
		}
	}
	arr[0][0] = nums[0][0];
	F0R(i, 1, r) {
		FOR(j, i + 1) {
			if (j == 0) {
				arr[i][j] = arr[i - 1][0] + nums[i][j];
				continue;
			}
			if (j == i) {
				arr[i][j] = arr[i - 1][j - 1] + nums[i][j];
				continue;
			}
			arr[i][j] = max(arr[i - 1][j - 1] + nums[i][j], arr[i - 1][j] + nums[i][j]);
		}
	}
	int ans = -1;
	FOR(i, r) {
		FOR(j, i + 1) {
			if (ans < arr[i][j]) {
				ans = arr[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
