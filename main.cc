#include <iostream>


const int    N = 171;	// Calculation goes wrong if the value over
			// 170 is set.
const double p =   0.8;


double factorial(int n)
{
  if (n == 0) {
    return 1.0;
  }
  else {
    return factorial(n - 1) * n;
  }
}

double binomial(int n, int k)
{
  double x =       factorial(n    );
  double y = 1.0 / factorial(n - k);
  double z = 1.0 / factorial(    k);

#if 0
  std::cout <<
    "n=" << n << ' ' <<
    "k=" << k << ' ' <<
    "x=" << std::fixed << x         << ' ' <<
    "y=" << std::fixed <<     y     << ' ' <<
    "z=" << std::fixed <<         z << ' ' <<
    "b=" << std::fixed << x * y * z << std::endl;
#endif

  return x * y * z;
}

double bindist(int n, double p, int k)
{
  double b = binomial(n, k);

  for (int i = 0; i < k; i ++)
    b *= p;

  for (int i = 0; i < n - k; i ++)
    b *= 1.0 - p;

  return b;
}


int main(int argc, char** argv)
{
  double s = 0.0;

  for (int k = 0; k < N; k ++)
    s += bindist(N, p, k);

  std::cout << std::fixed << s << std::endl;
}
