/**
 *
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Pos {
	float x, y;

	Pos() : x(0), y(0) {};

	Pos(float _x, float _y) : x(_x), y(_y) {};
};


float poly_func(float x) {
	// 绘制一个椭圆的左上部分模拟 车道线
	float a = 5, b = 4;
	float y = sqrt(b * b - b * b * (x - a) * (x - a) / (a * a));
	return y;
}

/**
 *
 * @param start_x
 * @param end_x
 * @param n
 * @return
 */
vector<Pos> curve_build(float start_x, float end_x, int n) {
	vector<Pos> curve;
	Pos tmp;
	float step = (end_x - start_x) / (float) n;
	for (int i = 0; i <= n; i++) {
		tmp.x = start_x + i * step;
		tmp.y = poly_func(tmp.x);
		curve.push_back(tmp);
	}
	return curve;
}

// const <type>  & 表示一个常量引用，引用使得输入变量无需拷贝，常量使得变量不会被改变
// 相较于直接传入参数，减少了拷贝的开销
/**
 *
 * @param curve
 * @param target
 * @return 	0 在曲线上
 * 			1 在曲线左边
 * 			2 在曲线右边
 */
int check_point_position(const vector<Pos> &curve, Pos target) {
	vector<float> dis(curve.size());
	int n = curve.size();
	int index = 0;
	float min;
	for (int i = 0; i < n; i++) {
		dis[i] = pow(target.x - curve[i].x, 2) + pow(target.y - curve[i].y, 2);
		if (i == 0) {
			min = dis[0];
			index = 0;
		}
		if (i != 0) {
			if (min > dis[i]) {
				min = dis[i];
				index = i;
			}
		}
	}
	for (auto i: dis) {
		cout << i << endl;
	}
	int alpha = 1;
	int index_p1 = index + alpha;
	int index_p2 = index - alpha;
	if (index_p1 > n - 1) index_p1 = n - 1;
	if (index_p2 < 0) index_p2 = 0;
	Pos p1 = curve[index_p1], p2 = curve[index_p2];
	Pos vec_p1p2, vec_p1tg;
	vec_p1p2.x = p1.x - p2.x;
	vec_p1p2.y = p1.y - p2.y;
	vec_p1tg.x = p1.x - target.x;
	vec_p1tg.y = p1.y - target.y;

	float inner_product = vec_p1p2.x * vec_p1tg.y - vec_p1p2.y * vec_p1tg.x;
	if (inner_product > 0) return 2; // right
	if (inner_product < 0) return 1;  // left
	if (inner_product == 0) return 0;
}

int main() {
	vector<Pos> curve = curve_build(0, 5, 100);
	Pos target(0, 2.5);
	cout << check_point_position(curve, target);
}
