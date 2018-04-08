/*
ID: eed7573
TASK: sort3
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
int arr[1000];
int inv[3][3];
int main() {
	FAST
	ofstream cout("sort3.out");
	ifstream cin("sort3.in");
	cin >> n;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	FOR(i, n) {
		int next;
		cin >> next;
		if (next == 1) {
			count0++;
		}
		else if (next == 2) {
			count1++;
		}
		else {
			count2++;
		}
		arr[i] = next - 1;
	}
	FOR(i, n) {
		if (i < count0) {
			if (arr[i] == 1) {
				inv[1][0]++;
			}
			else if (arr[i] == 2) {
				inv[2][0]++;
			}
		}
		else if (i < count0 + count1) {
			if (arr[i] == 0) {
				inv[0][1]++;
			}
			else if (arr[i] == 2) {
				inv[2][1]++;
			}
		}
		else {
			if (arr[i] == 0) {
				inv[0][2]++;
			}
			else if (arr[i] == 1) {
				inv[1][2]++;
			}
		}
	}
	int counter = 0;
	FOR(i, 2) {
		F0R(j, i + 1, 3) {
			int minim = min(inv[i][j], inv[j][i]);
			counter += minim;
			inv[i][j] -= minim;
			inv[j][i] -= minim;
		}
	}
	int left = max(inv[0][1], inv[0][2]);
	counter += 2 * left;
	cout << counter << endl;
	return 0;
}
