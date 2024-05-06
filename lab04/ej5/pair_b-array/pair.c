#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
  pair_t pair;
  pair.values[0] = x;
  pair.values[1] = y;

  assert(pair.values[0] == x && pair.values[1] == y);
  return pair; 
}

int pair_first(pair_t p) {
  int first = p.values[0];

  assert(first == p.values[0]);
  return first;
}

int pair_second(pair_t p) {
  int second = p.values[1];
  
  assert(second == p.values[1]);
  return second;
}

pair_t pair_swapped(pair_t p) {
  pair_t q;
  q.values[0] = pair_second(p);
  q.values[1] = pair_first(p);

  assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
  return q;
}

pair_t pair_destroy(pair_t p) {
  p.values[0] = 0;
  p.values[1] = 0;

  return p;
}

/*
  - En primera instancia, no se puede compilar porque la implementación es distinta
    y el método "show_pair" rompe la abstracción del TAD.
  - No logra encapsulamiento porque se puede acceder y modificar el campo "values" del tipo,
    lo que permite romper la abstracción.
*/