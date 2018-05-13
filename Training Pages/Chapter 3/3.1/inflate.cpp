/*
ID: eed7573
TASK: inflate
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

#define maxM 10000

int arr[maxM];
int m, n;
int main() {
	FAST
	ofstream fout("inflate.out");
	ifstream fin("inflate.in");
	fin >> m >> n;
	FOR(i, n) {
		int poi, mi;
		fin >> poi >> mi;
		F0R(j, mi, m+1) {
			arr[j] = max(arr[j], arr[j - mi] + poi);
		}
	}
	int curM = arr[0];
	FOR(i, m + 1) {
		if (arr[i] > curM) curM = arr[i];
	}
	fout << curM << "\n";
	return 0;
}
