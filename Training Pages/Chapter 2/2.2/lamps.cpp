/*
ID: eed7573
TASK: lamps
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

int n, c;
bool arrOn[101];
bool arrOff[101];
bool arr[101];
vector<string> ans;
int main() {
	FAST
	ofstream cout("lamps.out");
	ifstream cin("lamps.in");
	cin >> n >> c;
	int next = 0;
	while (next != -1) {
		cin >> next;
		if (next != -1) {
			arrOn[next] = true;
		}
	}
	next = 0;
	while (next != -1) {
		cin >> next;
		if (next != -1) {
			arrOff[next] = true;
		}
	}
	FOR(i, 2) {
		FOR(j, 2) {
			FOR(k, 2) {
				FOR(l, 2) {
					if ((i + j + k + l) % 2 != c % 2 || (i + j + k + l) > c) continue;
					if (i == 1) {
						F0R(m, 1, n + 1) {
							arr[m] = true;
						}
					}
					else {
						F0R(m, 1, n + 1) {
							arr[m] = false;
						}
					}
					if (j == 1) {
						for (int m = 1; m < n + 1; m += 2) {
							arr[m] = !arr[m];
						}
					}
					if (k == 1) {
						for (int m = 2; m < n + 1; m += 2) {
							arr[m] = !arr[m];
						}
					}
					if (l == 1) {
						for (int m = 1; m < n + 1; m += 3) {
							arr[m] = !arr[m];
						}
					}
					F0R(m, 1, n + 1) {
						if (arrOn[m] && arr[m]) goto here;
						if (arrOff[m] && !arr[m]) goto here;
					}
					if (false) {
						here:
						continue;
					}
					string a = "";
					F0R(m, 1, n + 1) {
						a += !arr[m] ? "1" : "0";
					}
					ans.PB(a);
				}
			}
		}
	}
	if (ans.size() == 0) cout << "IMPOSSIBLE" << endl;
	else {
		sort(ans.begin(), ans.end());
		for (string str : ans) {
			cout << str << endl;
		}
	}
	return 0;
}
