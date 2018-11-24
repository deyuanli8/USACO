pair<pii, int> T[100005];
int ran[100005];
int sa[100005];
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
		sort(T, T + s.length());
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
