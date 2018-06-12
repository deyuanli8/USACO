/*
ID: eed7573
TASK: kimbits
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

ll n, l, I;
ll choo[32][32];
int main() {
	FAST
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
	cin >> n >> l >> I;
	choo[0][0] = 1;
	F0R(i, 1, n + 1) {
		FOR(j, n + 1) {
			if (j == 0 || j == i) {
				choo[i][j] = 1;
			}
			else {
				choo[i][j] = choo[i - 1][j] + choo[i - 1][j - 1];
			}
		}
	}
	int k = l;
	string number = "";
	FOR(i, n) {
		number.PB('0');
	}
	int last = n;
	int sLast = 0;
	int curCount = 0;
	while (I > 0 && k > 0) {
		curCount = (int)pow(2, k - 1);
		if (curCount >= I) {
			int ans = I - 1;
			int ind = 0;
			while (ans > 0) {
				number[n-ind-1] = ans % 2 + 48;
				ans /= 2;
				ind++;
			}
			break;
		}
		F0R(i, k - 1, last) {
			sLast = curCount;
			FOR(j, k) {
				curCount += choo[i][j];
			}
			if (i == last - 1) {
				k--;
				number[n-i-1] = '1';
				I -= sLast;
				last = i;
				break;
			}
			else if (curCount >= I) {
				k--;
				number[n-i-1] = '1';
				I -= sLast;
				last = i;
				break;
			}
		}
	}
	cout << number << "\n";
	return 0;
}
