#define C const

void f() {
  int C * A;
}

void f1() {
#pragma spf transform inline
  f();
}
