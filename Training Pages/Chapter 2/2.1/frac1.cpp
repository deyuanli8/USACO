/*
ID: eed7573
TASK: frac1
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

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
vector<pii> v;
bool comp(pii a, pii b) {
	return (double)a.F / a.S < (double)b.F / b.S;
}
int main() {
	FAST
		ofstream cout("frac1.out");
	ifstream cin("frac1.in");
	cin >> n;
	v.PB(MP(0, 1));
	v.PB(MP(1, 1));
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (__gcd(i, j) == 1) {
				v.PB(MP(j, i));
			}
		}
	}
	sort(v.begin(), v.end(), comp);
	for (pii pa : v) {
		cout << pa.first << "/" << pa.second << endl;
	}
	return 0;
}
