/*
ID: eed7573
TASK: rockers
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

int n, t, m;
vi v;
int ans = -1;
void test(vector<bool> vb) {
	int curSum = 0;
	FOR(i, n) {
		if (vb[i]) curSum++;
	}
	if (curSum <= ans && ans != -1) {
		return;
	}
	int numUsed = 0;
	int timeLeft = t;
	bool more = true;
	FOR(i, n) {
		if (vb[i]) {
			if (v[i] > timeLeft) {
				if (v[i] > t) return;
				timeLeft = t-v[i];
				numUsed++;
				if (numUsed == m) {
					return;
				}
			}
			else {
				timeLeft -= v[i];
			}
		}
	}
	if (ans == -1 || curSum > ans) {
		ans = curSum;
	}
}
void recurse(int index, vector<bool> vb) {
	if (index == n) {
		test(vb);
		return;
	}
	vb[index] = true;
	recurse(index + 1, vb);
	vb[index] = false;
	recurse(index + 1, vb);
}
int main() {
	FAST
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	cin >> n >> t >> m;
	int next;
	vector<bool> vb;
	FOR(i, n) {
		cin >> next;
		v.PB(next);
		vb.PB(false);
	}
	recurse(0, vb);
	cout << ans << "\n";
	return 0;
}
