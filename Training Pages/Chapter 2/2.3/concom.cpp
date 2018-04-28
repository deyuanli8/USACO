/*
ID: eed7573
TASK: concom
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

int n;
bool control[100][100];
int arr[100][100];
int main() {
	FAST
	ofstream fout("concom.out");
	ifstream fin("concom.in");
	fin >> n;
	FOR(x, n) {
		int i, j, p;
		fin >> i >> j >> p;
		i--;
		j--;
		arr[i][j] = p;
		if (p > 50) control[i][j] = true;
	}
	FOR(i, 100) {
		FOR(j, 100) {
			FOR(k, 100) {
				if (j == k || control[j][k]) continue;
				int per = arr[j][k];
				FOR(l,100) {
					if (control[j][l]) {
						per += arr[l][k];
					}
				}
				if (per > 50) control[j][k] = true;
			}
		}
	}
	FOR(i, 100) {
		FOR(j, 100) {
			if (control[i][j] && i!=j) {
				fout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}
	return 0;
}
