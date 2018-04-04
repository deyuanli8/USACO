/*
ID: eed7573
TASK: pprime
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

#define F0R(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define maxN 10000000
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool sieve[maxN];
int a, b;
string stri;
bool palindrome() {
	for (int i = 0; i < stri.size()/2+1; i++) {
		if (stri[i] != stri[stri.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	FAST
	ofstream cout("pprime.out");
	ifstream cin("pprime.in");
	sieve[0] = 1;
	sieve[1] = 1;
	cin >> a >> b;
	for (int x = 2; x <= min(b/2, maxN/2); x++) {
		if (sieve[x]) continue;
		for (int u = 2 * x; u <= min(b,maxN-1); u += x) {
			sieve[u] = true;
		}
	}
	for (int i = a; i <= min(b,maxN-1); i++) {
		if (sieve[i]) continue;
		stri = to_string(i);
		if (palindrome()) {
			cout << i << endl;
		}
	}
	return 0;
}
