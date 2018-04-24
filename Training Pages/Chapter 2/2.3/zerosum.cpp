/*
ID: eed7573
TASK: zerosum
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
int arr[9];
set<string> ans;
void recur(int index) {
	if (index == n) {
		int sum = 0;
		int lastNum = 1;
		int last=0;
		F0R(i, 2, n + 1) {
			if (arr[i - 1] == 0) {
				if (last == 0) sum += lastNum;
				else sum -= lastNum;
				last = 0;
				lastNum = i;
			}
			else if (arr[i - 1] == 1) {
				if (last == 0) sum += lastNum;
				else sum -= lastNum;
				last = 1;
				lastNum = i;
			}
			else {
				lastNum = lastNum * 10 + i;
			}
		}
		if (last == 0) sum += lastNum;
		else sum -= lastNum;
		if (sum == 0) {
			string a = "1";
			F0R(i, 2, n + 1) {
				if (arr[i - 1] == 0) {
					a += "+";
				}
				else if (arr[i - 1] == 1) {
					a += "-";
				}
				else {
					a += " ";
				}
				a += to_string(i);
			}
			ans.insert(a);
		}
		return;
	}
	arr[index] = 0;
	recur(index + 1);
	arr[index] = 1;
	recur(index + 1);
	arr[index] = 2;
	recur(index + 1);
}
int main() {
	FAST
	ofstream fout("zerosum.out");
	ifstream fin("zerosum.in");
	fin >> n;
	recur(0);
	for (string s : ans) {
		fout << s << "\n";
	}
	return 0;
}
