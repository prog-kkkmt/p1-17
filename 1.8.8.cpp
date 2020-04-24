#define MAX(x, y, r) ({typeof(x) _x = x; typeof(y) _y = y; \
      (r) = ( _x > _y ? _x : _y);})