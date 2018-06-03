/*
ID: eed7573
TASK: stamps
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

int arr[2000005];
vi v;
int k, n;
int main() {
	FAST
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	arr[0] = 0;
	cin >> k >> n;
	int next;
	FOR(i, n) {
		cin >> next;
		v.PB(next);
	}
	sort(v.begin(), v.end());
	F0R(i, 1, 2000005) {
		bool found = false;
		FOR(j, v.size()) {
			if (i - v[j] < 0) break;
			if (arr[i - v[j]] < k) {
				if (!found || arr[i] > arr[i - v[j]] + 1) {
					arr[i] = arr[i - v[j]] + 1;
					found = true;
				}
			}
		}
		if (!found) {
			cout << i-1 << "\n";
			return 0;
		}
	}
	return 0;
}
