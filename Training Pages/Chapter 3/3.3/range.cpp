/*
ID: eed7573
TASK: range
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
bool arr[250][250];
vp v;
int main() {
	FAST
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	string next;
	cin >> n;
	FOR(i, n) {
		cin >> next;
		FOR(j, n) {
			arr[i][j] = next[j] - 48;
			if (!(next[j]-48)) {
				v.PB(MP(i, j));
			}
		}
	}
	F0R(i, 1, n) {
		int counter = 0;
		FOR(j, n - i) {
			FOR(k, n - i) {
				int l = lower_bound(v.begin(), v.end(), MP(j, k)) - v.begin();
				int u = upper_bound(v.begin(), v.end(), MP(j + i, k + i)) - v.begin();
				if (l == u) {
					counter++;
				}
				else {
					bool b = true;
					F0R(m, l, u) {
						if (v[m].S >= k && v[m].S <= k + i) {
							b = false;
							break;
						}
					}
					if (b) {
						counter++;
					}
				}
			}
		}
		if (counter == 0) {
			break;
		}
		else {
			cout << i + 1 << " "<< counter << "\n";
		}
	}
	return 0;
}
