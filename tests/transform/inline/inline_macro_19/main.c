#define C :

int f() {
 return 1 ? 0 C 0;
}

void f1() {
#pragma spf transform inline
  f();
}
