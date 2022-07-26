#include "../inc/allInc.h"

void SetInOut(void) {
  DDRD |= _BV(DDD5);
  DDRD |= _BV(DDD6);
  DDRD |= _BV(DDD7);
}
