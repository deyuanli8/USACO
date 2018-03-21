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
#define MT make_tuple
#define SQ(a) (a)*(a)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 1000
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
int arr1[maxN];
int arr2[maxN];
int arr[maxN][maxN+1];
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main() {
	FAST
	ofstream cout("nocross.out");
	ifstream cin("nocross.in");
	cin >> n;
	int next;
	for (int i = 0; i < n; i++) {
		cin >> next;
		arr1[i] = next;
	}
	for (int i = 0; i < n; i++) {
		cin >> next;
		arr2[i] = next;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			arr[i][j] = -1;
		}
	}
	int fir, sec;
	for (int i = 0; i < n; i++) {
		int curMax = 0;
		int savedMax;
		bool found = false;
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				arr[i][j] = 0;
				continue;
			}
			fir = arr1[i];
			sec = arr2[j-1];
			if (i == 0) {
				arr[i][j] = 0;
				if (abs(fir - sec) <= 4) {
					for (int k = j; k < n; k++) {
						arr[i][k] = 1;
					}
					break;
				}
				continue;
			}
			curMax = max(curMax, arr[i - 1][j - 1]);
			if (abs(fir - sec) <= 4) {
				found = true;
				savedMax = curMax;
			}
			if (!found) {
				arr[i][j] = max(curMax, arr[i-1][j]);
				continue;
			}
			else {
				arr[i][j] = max(max(curMax, arr[i-1][j]), 1 + savedMax);
			}
		}
	}
	cout << arr[n - 1][n] << endl;
	return 0;
}
