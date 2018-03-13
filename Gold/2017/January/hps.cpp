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
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 100000
#define maxK 21
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, k;
int arr[maxN][maxK][3];
int moves[maxN];
int maxt(int a, int b, int c) {
	int curMax = a;
	if (b > curMax) curMax = b;
	if (c > curMax) curMax = c;
	return curMax;
}
int main() {
	FAST
	ofstream cout("hps.out");
	ifstream cin("hps.in");
	cin >> n >> k;
	char next;
	for (int i = 0; i < n; i++) {
		cin >> next;
		if (next == 'H') moves[i] = 0;
		else if (next == 'P') moves[i] = 1;
		else moves[i] = 2;
	}
	arr[0][0][0] = 0; arr[0][0][1] = 0; arr[0][0][2] = 0; arr[0][0][moves[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; (j <= i && j<=20); j++) {
			if (j == 0) {
				for (int h = 0; h < 3; h++) {
					if (moves[i] == h) {
						arr[i][j][h] = arr[i - 1][j][h] + 1;
					}
					else {
						arr[i][j][h] = arr[i - 1][j][h];
					}
				}
				continue;
			}
			for (int h = 0; h < 3; h++) {
				if (moves[i] == h) {
					arr[i][j][h] = maxt(arr[i - 1][j][h], arr[i - 1][j - 1][(h + 1) % 3], arr[i - 1][j - 1][(h + 2) % 3]) + 1;
				}
				else {
					arr[i][j][h] = maxt(arr[i - 1][j][h], arr[i - 1][j - 1][(h + 1) % 3], arr[i - 1][j - 1][(h + 2) % 3]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[n - 1][i][j] > ans) {
				ans = arr[n - 1][i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
