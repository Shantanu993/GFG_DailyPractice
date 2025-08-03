class Solution {
  public:
    struct Point {
        double x, y;
    };

    double cross(const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    double distanceSq(const Point& a, const Point& b) {
        return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    }

    void buildConvexHull(vector<Point>& points) {
        if (points.size() <= 2)
            return;

        // Find anchor point
        Point anchor = points[0];
        for (const Point& p : points) {
            if (p.y < anchor.y || (p.y == anchor.y && p.x < anchor.x))
                anchor = p;
        }

        // Sort by polar angle using a lambda that captures the anchor
        sort(points.begin(), points.end(), [&anchor](const Point& a, const Point& b) {
            double cp = (anchor.x * (a.y - b.y) + a.x * (b.y - anchor.y) +
                         b.x * (anchor.y - a.y));
            if (abs(cp) < 1e-10) // Fuzzy equality check
                return (pow(anchor.x - a.x, 2) + pow(anchor.y - a.y, 2)) <
                       (pow(anchor.x - b.x, 2) + pow(anchor.y - b.y, 2));
            return cp > 0;
        });

        // Build hull
        vector<Point> hull;
        for (const Point& p : points) {
            while (hull.size() >= 2) {
                Point top = hull.back();
                hull.pop_back();
                if (cross(hull.back(), top, p) > 0) {
                    hull.push_back(top);
                    break;
                }
            }
            hull.push_back(p);
        }

        points = hull;
    }

    vector<vector<int>> findConvexHull(vector<vector<int>>& points) {
        vector<Point> vp;
        for (const auto& pt : points) {
            vp.push_back({static_cast<double>(pt[0]), static_cast<double>(pt[1])});
        }

        buildConvexHull(vp);

        if (vp.size() <= 2)
            return {{-1}};

        vector<vector<int>> result;
        for (const auto& pt : vp) {
            result.push_back(
                {static_cast<int>(round(pt.x)), static_cast<int>(round(pt.y))});
        }
        sort(result.begin(), result.end());
        return result;
    }
};