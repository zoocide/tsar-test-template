double foo(double S, double Q) {
  for (int J = 0; J < 10; ++J) {
    for (int I = 0; I < 10; ++I) {
      S += I;
    }
    S = Q;
  }
  return S + Q;
}
