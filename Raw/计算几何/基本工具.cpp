#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI  = acos(-1);

int sgn(double x)  // 返回x的符号
{
	if (abs(x)<eps) return 0;
	return x>0 ? 1 : -1;
}

inline double sqr(double x) { return x*x; }

struct Point
{
	double x, y;

	Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {};
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double norm() {
		return sqrt(sqr(x)+sqr(y));
	}

	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x+b.x, a.y+b.y);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x-b.x, a.y-b.y);
	}
	friend Point operator * (const Point &a, const double &b) {
		return Point(a.x*b, a.y*b);
	}
	friend Point operator / (const Point &a, const double &b) {
		return Point(a.x/b, a.y/b);
	}
	friend bool operator == (const Point &a, const Point &b) {
		return sgn(a.x-b.x)==0 && sgn(a.y-b.y)==0;
	}
};

// 叉积
double det(const Point &a, const Point &b) {
	return a.x*b.y-a.y*b.x;
}

// 点积
double dot(const Point &a, const Point &b) {
	return a.x*b.x+a.y*b.y;
}

// 两点间距离
double dist(const Point &a, const Point &b) {
	return (a-b).norm();
}

// 将向量绕原点逆时针旋转弧度A（由旋转前后模长不变推导）
// 绕任意点Q旋转，只需在答案中追加Q的横纵坐标
Point rotate(const Point &p, double A) {
	double tx=p.x, ty=p.y;
	return Point(tx*cos(A)-ty*sin(A), tx*sin(A)+ty*cos(A));
}
