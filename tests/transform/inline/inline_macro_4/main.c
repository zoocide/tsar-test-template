void f() { int X;}

#define MACRO(f_) f_(); X = 5;

void f1() {
  int X;
#pragma spf transform inline
  MACRO(f)
}
