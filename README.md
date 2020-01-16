# 概要
- 任意の浮動小数点座標を3つ（double値で6つ分）渡すことで、それら座標が三角形を構成するかどうかを判定するライブラリです。
- `bool is_triangle(double x0, double y0, double x1, double y1, double x2, double y2);`に対し、`(x0, y0), (x1, y1), (x2, y2)`で表される点の座標をそれぞれ渡すことで判定が可能です。
# 使用方法
- `is_string.hpp`をincludeしてください。依存はC++標準ライブラリのみです。
- `make test`でテストのビルド〜実行が可能です。テスト実行にはGoogle Testがインストールされている必要があります。
# 補足：計算精度について
- double値の比較は自作関数`is_equal_d()`で行っており、標準ライブラリ`limits`で定義される機械イプシロン（`std::numeric_limits<double>::epsilon()` ）を利用しています。2値の差分が大きい方の絶対値に占める割合を計算し、それが機械イプシロンを下回った場合に「等しい」と判定します。
- doubleが64bit幅の環境での有効桁数は15〜16桁程度となります。割合で誤差を判定しているため、許容誤差の（入力に依存しない）絶対的な値は定義されません。
# 環境
- OS: Manjaro 18.1.5
- Compiler: Clang 9.0.0
- Test Framework: Google Test 1.10.0
