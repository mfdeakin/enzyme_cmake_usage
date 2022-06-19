
#include <iostream>

using fnptr = double (*)(double);

extern double __enzyme_autodiff(fnptr fn, double v);

double square(double x) { return x * x; }
double square_diff(double x) { return 2.0 * x; }

int main() {
  constexpr double x = 5.0;
  std::cout << "x^2 @x=" << x << ": " << square(x) << ", " << __enzyme_autodiff(square, x) << ", expected " << square_diff(x) << std::endl;
  return 0;
}
