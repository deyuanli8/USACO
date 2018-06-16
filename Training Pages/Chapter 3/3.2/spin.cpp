/*
ID: eed7573
TASK: spin
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

vi v(5);
bool arr[5][360];
int main() {
	FAST
	//freopen("spin.in", "r", stdin);
	//freopen("spin.out", "w", stdout);
	FOR(i, 5) {
		cin >> v[i];
		int num;
		cin >> num;
		int fir, sec;
		FOR(j, num) {
			cin >> fir >> sec;
			F0R(k, fir, fir + sec + 1) {
				arr[i][k % 360]=true;
			}
		}
	}
	FOR(i, 360) {
		FOR(k, 360) {
			bool ans = true;
			FOR(j, 5) {
				if (!arr[j][((k - v[j] * i) % 360 + 360) % 360]) {
					ans = false;
					break;
				}
			}
			if (ans) {
				cout << i << "\n";
				return 0;
			}
		}
	}
	cout << "none" << "\n";
	return 0;
}
