/*
ID: eed7573
TASK: nuggets
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
#include <bitset>
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
vi v;
bool arr[65026];
int main() {
	FAST
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	cin >> n;
	FOR(i, n) {
		int next;
		cin >> next;
		v.PB(next);
	}
	arr[0] = true;
	FOR(i, n) {
		FOR(j, 65026 - v[i]) {
			if (arr[j]) {
				arr[j + v[i]] = true;
			}
		}
	}
	if (!arr[65025]) {
		cout << 0 << "\n";
		return 0;
	}
	FORd(i, 65024) {
		if (!arr[i]) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}
