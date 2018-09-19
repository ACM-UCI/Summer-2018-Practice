#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int popes[101000];

int main() {
  int y, p;
  while (GET(y) > 0) {
    GET(p);
    FOR(i, 0, p) { GET(popes[i]); }

    int mx = 0;
    int first = 0;
    int last = 0;
    for (int i = 0; i < p; ++i) {
      int* last_pos = upper_bound(popes, popes + p, popes[i] + y - 1);
      int num = last_pos - (popes + i);
      if (num > mx) {
        mx = num;
        first = popes[i];
        last = popes[i + num - 1];
      }
    }

    printf("%d %d %d\n", mx, first, last);
  }
  return 0;
}
