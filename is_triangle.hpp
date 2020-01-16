#include <limits>
#include <algorithm>

bool is_equal_d(double a, double b) {
  const double difference = std::abs(a - b);
  const double bigger_abs = std::max(std::abs(a), std::abs(b));
  // 2つのdouble値の差分（絶対値）が大きい方のdouble値の何%かを計算し、それが機械イプシロン未満なら等しいとみなす
  // 機械イプシロンは許容誤差の働きをする
  return (bigger_abs == 0 || difference < std::numeric_limits<double>::epsilon() * bigger_abs)
    ? true
    : false;
}

bool is_triangle(double x0, double y0, double x1, double y1, double x2, double y2) {
  // 共線条件：3点が同一直線上に存在する時、この式は0をとる
  const double collinear_condition = ((x0 * y1 - y0 * x1) + (x1 * y2 - y1 * x2) + (x2 * y0 - y2 * x0));

  // 比較には浮動小数点の誤差を考慮した関数を用いる
  if (is_equal_d(collinear_condition, 0.0)) {
    return false;
  }

  return true;
}
