/*
ID: eed7573
TASK: ratios
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

int arr[4][3];
vi v(3);
vi sum(3);
int ans = 0;
bool recurse(int a, int b) {
	if (b == 2) {
		v[2] = a;
		FOR(i, 3) {
			sum[i] = 0;
			FOR(j, 3) {
				sum[i] += v[j] * arr[j + 1][i];
			}
		}
		if ((double)sum[0] / sum[1] == (double)(arr[0][0]) / arr[0][1] && (double)sum[0] / sum[2] == (double)(arr[0][0]) / arr[0][2] && arr[0][0]*(sum[0]/arr[0][0])==sum[0]) {
			ans = sum[0] / arr[0][0];
			return true;
		}
		return false;
	}
	FOR(i, a + 1) {
		v[b] = i;
		if (recurse(a - i, b + 1)) {
			return true;
		}
	}
	return false;
}
int main() {
	FAST
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	FOR(i, 4) {
		FOR(j, 3) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 298) {
		if (recurse(i, 0)) {
			cout << v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<ans<<"\n";
			return 0;
		}
	}
	cout << "NONE" << "\n";
	return 0;
}
