#include <stdlib.h>
#include <assert.h>
#include "pair.h"

struct s_pair_t {
  elem fst;
  elem snd;
};

pair_t pair_new(elem x, elem y) {
  pair_t pair = NULL;
  pair = malloc(sizeof(x) + sizeof(y));
  pair -> fst = x;
  pair -> snd = y;

  assert(pair -> fst == x && pair -> snd == y);
  return pair;
}

elem pair_first(pair_t p) {
  elem first = p -> fst;

  assert(first == p -> fst);
  return first;
}

elem pair_second(pair_t p) {
  elem second = p -> snd;

  assert(second == p -> snd);
  return second;
}

pair_t pair_swapped(pair_t p) {
  pair_t q = NULL;
  q = malloc(sizeof(p));
  q -> fst = pair_second(p); 
  q -> snd = pair_first(p);

  assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
  return q;
}

pair_t pair_destroy(pair_t p) {
  free(p);
  p = NULL;

  return p;
}

/*
  A diferencia de la especificación anterior, esta es polimórfica, lo que nos permite tener tuplas de cualquier tipo de elemento.
*/

