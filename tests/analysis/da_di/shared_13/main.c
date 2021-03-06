int IStart, IEnd, JStart, JEnd;

void bar();

void foo(double (* restrict U)[100]) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    ++JStart;
    // JStart is not invariant for outer loop.
    // So, analyzer conservatively assumes dependencies for outer loop.
    for (J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;  
  }
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 shared_13.c:7:3
//SAFE:    private:
//SAFE:     <J:6, 4>
//SAFE:    output:
//SAFE:     <*U:5, ?> | <JStart, 4>
//SAFE:    anti:
//SAFE:     <*U:5, ?> | <JStart, 4>
//SAFE:    flow:
//SAFE:     <*U:5, ?> | <JStart, 4>
//SAFE:    induction:
//SAFE:     <I:7[7:3], 4>:[Int,,,1]
//SAFE:    read only:
//SAFE:     <IEnd, 4> | <JEnd, 4> | <U:5, 8>
//SAFE:    lock:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4>
//SAFE:    header access:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4>
//SAFE:    explicit access:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4> | <J:6, 4> | <JEnd, 4> | <JStart, 4> | <U:5, 8>
//SAFE:    explicit access (separate):
//SAFE:     <I:7[7:3], 4> <IEnd, 4> <J:6, 4> <JEnd, 4> <JStart, 4> <U:5, 8>
//SAFE:    lock (separate):
//SAFE:     <I:7[7:3], 4> <IEnd, 4>
//SAFE:    direct access (separate):
//SAFE:     <*U:5, ?> <I:7[7:3], 4> <IEnd, 4> <J:6, 4> <JEnd, 4> <JStart, 4> <U:5, 8>
//SAFE:   loop at depth 2 shared_13.c:11:5
//SAFE:     shared:
//SAFE:      <*U:5, ?>
//SAFE:     induction:
//SAFE:      <J:6, 4>:[Int,,,1]
//SAFE:     read only:
//SAFE:      <I:7[7:3], 4> | <JEnd, 4> | <U:5, 8>
//SAFE:     lock:
//SAFE:      <J:6, 4> | <JEnd, 4>
//SAFE:     header access:
//SAFE:      <J:6, 4> | <JEnd, 4>
//SAFE:     explicit access:
//SAFE:      <I:7[7:3], 4> | <J:6, 4> | <JEnd, 4> | <U:5, 8>
//SAFE:     explicit access (separate):
//SAFE:      <I:7[7:3], 4> <J:6, 4> <JEnd, 4> <U:5, 8>
//SAFE:     lock (separate):
//SAFE:      <J:6, 4> <JEnd, 4>
//SAFE:     direct access (separate):
//SAFE:      <*U:5, ?> <I:7[7:3], 4> <J:6, 4> <JEnd, 4> <U:5, 8>
