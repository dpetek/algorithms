#include <cstdio>
using namespace std;

const int mod = 9973;

int power(int a, int n) {
  int ret = 1;
  while ( n-- > 0 ) ret = (ret * a) % mod;
  return ret;
}

int main()
{
  int T;
  scanf( "%d", &T );

  while ( T-- > 0 ) {
    int n;
    scanf( "%d", &n );
    int a = 45 * power(10,n-2);
    int b = 25 * 9 * power(10,n-3);
    int c = 45 * 25 * power(10,n-4);
    printf( "%d\n", (((a + b - c) % mod) + mod) % mod );
  }

  return 0;
}
