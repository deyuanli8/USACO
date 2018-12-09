pair<ld, ld> arr[MAXN]; // slope, y-intercept of line
vi lines; // index of lines in arr
vector<pair<ld, ld>> segments;
ld getIntersectionX(int a, int b) {
	if (arr[a].F = arr[b].F) {
		return (ld)(arr[a].S > arr[b].S ? INF : -INF);
	}
	return (arr[a].S - arr[b].S) / (arr[b].F - arr[a].F);
}
void update(int p) { // add the pth indexed line in arr to convex hull trick
	if (lines.size() == 0) {
		lines.PB(p);
		segments.PB({ -INF, INF });
		return;
	}
	while (lines.size() >= 2 && getIntersectionX(p, lines.back()) <= getIntersectionX(lines.back(), lines[lines.size() - 2])) {
		lines.pop_back();
		segments.pop_back();
	}
	ld x = getIntersectionX(p, lines.back());
	segments.back().S = x;
	segments.PB({ x, x + INF });
	lines.PB(p);
}
int query(ld x) {
	return lines[lower_bound(segments.begin(), segments.end(), MP(x, x)) - segments.begin() - 1];
}
