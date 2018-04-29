/*
ID: eed7573
TASK: nocows
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

#define maxN 200
#define maxK 100
#define MOD 9901

int arr[2][maxN + 1][maxN + 1];
int choo[maxN + 1][maxN + 1];
int n, k;
int main() {
	FAST
	ofstream cout("nocows.out");
	ifstream cin("nocows.in");
	cin >> n >> k;
	FOR(i, n + 1) {
		FOR(j, i + 1) {
			if (i == 0 || j == 0 || j == i) choo[i][j] = 1;
			else {
				choo[i][j] = (choo[i - 1][j - 1] + choo[i - 1][j]) % MOD;
			}
		}
	}
	arr[1][1][1] = 1;
	F0R(i, 2, k + 1) {
		for (int j = 2 * i - 1; j < n + 1; j += 2) {
			for (int r = 2; r < j; r += 2) {
				for (int l = r / 2; l < j - r + 1; l++) {
					arr[i % 2][j][r] = (arr[i % 2][j][r] + arr[(i + 1) % 2][j - r][l] * choo[l][r / 2]) % MOD;
				}
			}
		}
		FOR(j, n + 1) {
			FOR(k, n + 1) {
				arr[(i + 1) % 2][j][k] = 0;
			}
		}
	}
	int counter = 0;
	FOR(i, n + 1) {
		counter = (counter + arr[k%2][n][i]) % MOD;
	}
	cout << counter << "\n";
	return 0;
}
