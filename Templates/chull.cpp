vector<point> pointset;
bool compA(point a, point b) {
	return (a.X < b.X) || (a.X == b.X && a.Y < b.Y);
}
vector<point> chull() {
	vector<point> hull;
	sort(pointset.begin(), pointset.end(), compA);
	FOR(i, pointset.size()) {
		point a = pointset[i];
		while (hull.size() >= 2 && (conj((hull[hull.size() - 1] - hull[hull.size() - 2]))*(a - hull[hull.size() - 1])).Y > 0) {
			hull.pop_back();
		}
		hull.PB(a);
	}
	FORd(i, pointset.size() - 1) {
		point a = pointset[i];
		while (hull.size() >= 2 && (conj((hull[hull.size() - 1] - hull[hull.size() - 2]))*(a - hull[hull.size() - 1])).Y > 0) {
			hull.pop_back();
		}
		hull.PB(a);
	}
	hull.pop_back();
	return hull;
}
