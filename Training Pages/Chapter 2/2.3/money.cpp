/*
ID: eed7573
TASK: money
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

#define maxN 10000
int v, n;
ll arr[maxN+1];
vi coins;
int main() {
	FAST
	ofstream fout("money.out");
	ifstream fin("money.in");
	fin >> v >> n;
	int nCoin;
	FOR(i, v) {
		fin >> nCoin;
		coins.PB(nCoin);
	}
	arr[0] = 1;
	FOR(i, v) {
		int value = coins[i];
		FOR(j, n - value + 1) {
			arr[j + value] += arr[j];
		}
	}
	fout << arr[n]<<"\n";
	return 0;
}
