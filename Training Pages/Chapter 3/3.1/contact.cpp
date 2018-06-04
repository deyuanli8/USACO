/*
ID: eed7573
TASK: contact
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
#include <chrono>
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

int a, b, n;
pii arr[8192];
string s;
ll strLen = 0;
int dif = 0;
string tobin(int p) {
	if (p == 1) return "";
	return tobin(p / 2) + to_string(p % 2);
}
int main() {
	FAST
		//freopen("contact.in", "r", stdin);
		//freopen("contact.out", "w", stdout);
		ifstream cin("contact.in");
	ofstream cout("contact.out");
	cin >> a >> b >> n;
	int c = 1;
	string s1;
	while (getline(cin, s1)) {
		s += s1;
		strLen += s1.length();
	}
	FOR(i, strLen) {
		int num = 0;
		int len = 1;
		FOR(j, b) {
			if (i + j == strLen) break;
			num = 2 * num + s[i + j] - 48;
			len *= 2;
			if (j + 1 >= a) {
				if (arr[num + len].first == 0) dif++;
				arr[num + len] = MP(arr[num + len].F + 1, -(num + len));
			}
		}
	}
	sort(arr, arr + 8192);
	int index = 8191;
	int numP;
	FOR(numF, n) {
		if (index <= -1 || arr[index].first==0) break;
		int k = arr[index].F;
		cout << arr[index].F << "\n";
		numP = 0;
		while (arr[index].F == k) {
			if (index <= -1) break;
			if (numP == 6) {
				numP = 0;
				cout << "\n";
			}
			if (numP != 0) {
				cout << " ";
			}
			cout << tobin(-arr[index].S);
			index--;
			numP++;
		}
		cout << "\n";
	}
	return 0;
}
