#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
  pair_t pair;
  pair.fst = x;
  pair.snd = y;

  assert(pair.fst == x && pair.snd == y);
  return pair;
}

int pair_first(pair_t p) {
  int first = p.fst;

  assert(first == p.fst);
  return first;
}

int pair_second(pair_t p) {
  int second = p.snd;

  assert(second == p.snd);
  return p.snd;
}

pair_t pair_swapped(pair_t p) {
  pair_t q;
  q.fst = pair_second(p);
  q.snd = pair_first(p);

  assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
  return q;
}

pair_t pair_destroy(pair_t p) {
  p.fst = 0;
  p.snd = 0;

  return p;
}