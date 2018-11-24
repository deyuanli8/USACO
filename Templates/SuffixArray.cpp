pair<pii, int> T[100005];
int ran[100005];
int sa[100005];

int cnt[100005]; // cnt[i] = number of occurences of i in A
int ranker[100005];
pair<pii, int> tem[100005]; // temporary array
void countingSort(int sz) {
	FOR(i, sz) {
		cnt[T[i].F.S]++;
	}
	F0R(i, 1, sz) {
		ranker[i] = ranker[i - 1] + cnt[i - 1];
		cnt[i - 1] = 0;
	}
	cnt[sz - 1] = 0;
	FOR(i, sz) {
		tem[ranker[T[i].F.S]] = T[i];
		ranker[T[i].F.S]++;
	}
	FOR(i, sz) {
		T[i] = tem[i];
	}
	ranker[0] = 0;
	FOR(i, sz) {
		cnt[T[i].F.F]++;
		ranker[i] = 0;
	}
	F0R(i, 1, sz) {
		ranker[i] = ranker[i - 1] + cnt[i - 1];
		cnt[i - 1] = 0;
	}
	cnt[sz - 1] = 0;
	FOR(i, sz) {
		tem[ranker[T[i].F.F]] = T[i];
		ranker[T[i].F.F]++;
	}
	FOR(i, sz) {
		T[i] = tem[i];
	}
	ranker[0] = 0;
}
void getSuffixArray(string s) {
	FOR(i, s.length()) ran[i] = 0;
	for (int len = 1; len <= s.length(); len *= 2) { // sort by first len characters
		FOR(i, s.length()) {
			if (len == 1) {
				T[i] = { {0,(int)s[i]}, i };
			}
			else {
				int b = i + len < s.length() ? ran[i + len] : -1;
				T[i] = { {ran[i], b}, i };
			}
		}
		countingSort(s.length());
		FOR(i, s.length()) {
			if (i > 0 && T[i].first == T[i - 1].first)
				ran[T[i].second] = ran[T[i - 1].second];
			else
				ran[T[i].second] = i;
		}
	}
	FOR(i, s.length()) {
		sa[ran[i]] = i;
	}
}
