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

int display[100];

int main() {
  int t;
  GET(t);
  getchar();
  FORe(ca, 1, t) {
    memset(display, 0, sizeof(display));
    char ch;
    int pos = 0;

    // interpret
    while ((ch = getchar()) != EOF && ch != '\n') {
      switch (ch) {
        case '+':
          ++display[pos];
          break;
        case '-':
          --display[pos];
          break;
        case '<':
          --pos;
          break;
        case '>':
          ++pos;
          break;
      }
      if (pos == 100) pos = 0;
      if (pos == -1) pos = 99;
      if (display[pos] == 256) display[pos] = 0;
      if (display[pos] == -1) display[pos] = 255;
    }

    // output
    printf("Case %d:", ca);
    FOR(i, 0, 100) { printf(" %02X", display[i]); }
    PLN;
  }
  return 0;
}
