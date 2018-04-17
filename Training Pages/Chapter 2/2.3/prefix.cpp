/*
ID: eed7573
TASK: prefix
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

string s="";
vector<string> v;
bool arr[200000];
int main() {
	FAST
	ofstream cout("prefix.out");
	ifstream cin("prefix.in");
	int maxS = 0;
	string next = "";
	cin >> next;
	do {
		v.PB(next);
		maxS = max(maxS, (int)next.size());
		cin >> next;
	} while (next != ".");
	while (cin >> next) {
		s += next;
	}
	arr[0] = true;
	int counter = 0;
	int last = 0;
	F0R(i, 1, s.length()+1) {
		FOR(j, v.size()) {
			if (i >= v[j].size() && arr[i-v[j].size()]) {
				FOR(k, v[j].size()) {
					if (v[j][k] != s[i - v[j].size() + k]) {
						goto here;
					}
				}
				arr[i] = true;
				last = i;
				counter = 0;
				here:
					continue;
				
			}
		}
		if (!arr[i]) {
			counter++;
			if (counter == maxS) {
				break;
			}
		}
	}
	cout << last << endl;
	return 0;
}
