#include <stdlib.h>
#include <assert.h>
#include "pair.h"

struct s_pair_t {
  int fst;
  int snd;
};

pair_t pair_new(int x, int y) {
  pair_t pair = NULL;
  pair = malloc(sizeof(x) + sizeof(y));
  pair -> fst = x;
  pair -> snd = y;

  assert(pair -> fst == x && pair -> snd == y);
  return pair;
}

int pair_first(pair_t p) {
  int first = p -> fst;

  assert(first == p -> fst);
  return first;
}

int pair_second(pair_t p) {
  int second = p -> snd;

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
  La implementación logra encapsulamiento ya que no podemos conocer ni manipular los datos del TAD
  fuera de los métodos proporcionados por la especificación.
*/

