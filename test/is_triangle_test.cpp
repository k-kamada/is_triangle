#include <gtest/gtest.h>
#include <limits>

#include "../is_triangle.hpp"

// テスト用の機械イプシロンはコンパイル時定数として用意
constexpr double epsilon = std::numeric_limits<double>::epsilon();

// 倍精度浮動小数点の比較関数
TEST(is_equal_d, helper_func_test) {
  ASSERT_EQ(true, is_equal_d(1.2345, 1.2345));
  // 許容誤差は比較する値の絶対値に依存
  ASSERT_EQ(true, is_equal_d(1e-15, 1e-15));
  ASSERT_EQ(false, is_equal_d(1e-15, 1e-15 + 1e-15));
  ASSERT_EQ(true, is_equal_d(1e+15, 1e+15 + 0.1));  // 1e+15オーダーに対しては、誤差0.1を許容
  ASSERT_EQ(false, is_equal_d(1e+15, 1e+15 + 0.2)); // 0.2は不可
}

// Valid: 3点が異なり、共線条件を満たさない
TEST(is_triangle, valid) {
  ASSERT_EQ(true, is_triangle(4.2, 3.8, 0.0, 0.2, 2.3, 8.4));
  ASSERT_EQ(true, is_triangle(epsilon, epsilon, 0, 0, -epsilon, epsilon));
  ASSERT_EQ(true, is_triangle(1e+15, 3.8, 2e+15, 0.2, -3e+15, 8.4));
}

// Not Valid: 3点が同一座標
TEST(is_triangle, all_dup) {
  ASSERT_EQ(false, is_triangle(1.23456, 1.23456, 1.23456, 1.23456, 1.23456, 1.23456));
  ASSERT_EQ(false, is_triangle(1e+15, 1e+15, 1e+15, 1e+15, 1e+15, 1e+15));
  ASSERT_EQ(false, is_triangle(epsilon, epsilon, epsilon, epsilon, epsilon, epsilon));
}

// Not Valid: 2点が同一座標
TEST(is_triangle, two_positions_dup) {
  ASSERT_EQ(false, is_triangle(2.0, 2.0, 2.0, 2.0, 3.4, 3.8)); // (x0, y0) == (x1, y1)
  ASSERT_EQ(false, is_triangle(3.4, 3.8, 2.0, 2.0, 2.0, 2.0)); // (x1, y1) == (x2, y2)
  ASSERT_EQ(false, is_triangle(2.0, 2.0, 3.8, 3.8, 2.0, 2.0)); // (x0, y0) == (x2, y2)
}

// Not Valid: 3点のxまたはy座標がそれぞれ全て等しい
TEST(is_triangle, three_x_or_y_dup) {
  ASSERT_EQ(false, is_triangle(0.1, 0.111, 0.1, 0.222, 0.1, 0.333)); // x0 = x1 = x2
  ASSERT_EQ(false, is_triangle(0.111, 0.1, 0.222, 0.1, 0.333, 0.1)); // y0 = y1 = y2
}

// Not Valid: 共線条件に違反（3点が同一直線上に配置）
TEST(is_triangle, collinear) {
  ASSERT_EQ(false, is_triangle(0.0, 0.0, 0.05, 0.05, 0.1, 0.1));
  ASSERT_EQ(false, is_triangle(-0.1234, 0.2468, 0.0, 0.0, 0.2468, -0.4936));
  ASSERT_EQ(false, is_triangle(0.0, 0.0, epsilon, epsilon, -epsilon, -epsilon));
  ASSERT_EQ(false, is_triangle(-1e+15, -1e+15, 0.0, 0.0, 1e+15, 1e+15));
}
