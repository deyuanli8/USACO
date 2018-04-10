/*
ID: eed7573
TASK: hamming
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

int n, b, d;
vi ans;
bool nums[256];
int hamming(int p, int q) {
	int counter = 0;
	FOR(i, b) {
		if (p % 2 != q % 2) counter++;
		p /= 2;
		q /= 2;
	}
	return counter;
}
int main() {
	FAST
	ofstream cout("hamming.out");
	ifstream cin("hamming.in");
	cin >> n >> b >> d;
	int counter = 0;
	FOR(i, (int)pow(2,b)) {
		if (nums[i]) continue;
		ans.PB(i);
		counter++;
		if (counter == n) break;
		F0R(j, i, (int)pow(2,b)) {
			if (!nums[j] && hamming(i, j) < d) {
				nums[j] = true;
			}
		}
	}
	int c = 0;
	FOR(i, n) {
		if (c == 0) cout << ans[i];
		else {
			cout << " " << ans[i];
		}
		c = (c + 1) % 10;
		if (c == 0) cout << endl;
	}
	if (c != 0) cout << endl;
	return 0;
}
