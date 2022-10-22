#include "../inc/allInc.h"

void SetInOut(void) {
  DDRD |= _BV(DDD2);
  DDRD |= _BV(DDD3);
  DDRD |= _BV(DDD4);
  DDRD |= _BV(DDD5);
  DDRD |= _BV(DDD6);
  DDRD |= _BV(DDD7);
  DDRC |= _BV(DDC0);
  DDRC |= _BV(DDC1);
  DDRC |= _BV(DDC2);
  DDRC |= _BV(DDC3);
  DDRC |= _BV(DDC4);
  DDRC |= _BV(DDC5);
}
