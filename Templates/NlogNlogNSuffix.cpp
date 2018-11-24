pair<pii, int> T[100005];
int ran[100005];
int sa[100005];
int lcp[100005];
void getSuffixArray(string& s) {
	FOR(i, s.length()) ran[i] = 0;
	FOR(i, s.length()) {
		T[i] = { {0,(int)s[i]}, i };
	}
	sort(T, T + s.length());
	FOR(i, s.length()) {
		if (i > 0 && T[i].first == T[i - 1].first)
			ran[T[i].second] = ran[T[i - 1].second];
		else
			ran[T[i].second] = i;
	}
	for (int len = 1; len <= s.length(); len *= 2) { // sort by first len characters
		FOR(i, s.length()) {
			int b = i + len < s.length() ? ran[i + len] : -1;
			T[i] = { {ran[i], b}, i };
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
void constructLCP(string& s) {
	int sz = s.size();
	int k = 0;
	for (int i = 0; i < sz; i++, k ? k-- : 0) {
		if (ran[i] == sz - 1) {
			k = 0;
			continue;
		}
		int j = sa[ran[i] + 1];
		while (i + k < sz && j + k < sz && s[i + k] == s[j + k]) k++;
		lcp[ran[i]] = k;
	}
}
