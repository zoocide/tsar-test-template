int foo(int a) { return a * a; }

int main() {
  int y, x = 5;

  /* foo(x) is inlined below */
  int R0;
#pragma spf assert nomacro
  {
    int a0 = x;
    R0 = a0 * a0;
  }
  y = R0;
  return 0;
}
