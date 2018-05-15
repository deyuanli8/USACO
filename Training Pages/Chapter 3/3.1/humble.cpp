/*
ID: eed7573
TASK: humble
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

int k, n;
vi v;
ll arr[100001];
int main() {
	FAST
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	cin >> k >> n;
	FOR(i, k) {
		int j;
		cin >> j;
		v.PB(j);
	}
	sort(v.begin(), v.end());
	FOR(i, n+1) {
		if (i == 0) {
			arr[0] = 1;
			continue;
		}
		ll curMin = -1;
		FOR(j, k) {
			int ne = lower_bound(arr, arr + i, (ld)(arr[i - 1] + 1) / v[j]) - arr;
			if (curMin == -1 || curMin > arr[ne]*v[j]) {
				curMin = arr[ne] * v[j];
			}
		}
		arr[i] = curMin;
	}
	cout << arr[n] << "\n";
	return 0;
}
