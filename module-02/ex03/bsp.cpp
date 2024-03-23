#include "Point.hpp"

float area(Point a, Point b, Point c) {
  Fixed area = (
    a.getX() * (b.getY() - c.getY()) + 
    b.getX() * (c.getY() - a.getY()) +
    c.getX() * (a.getY() - b.getY())) / 2.0f;

  return (area < 0 ? area.toFloat() * -1 : area.toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const x) {
  float abc = area(a, b, c);
  float xab = area(x, a, b);
  float xbc = area(x, b, c);
  float xac = area(x, a, c);

  return (xab + xbc + xac == abc ? true : false);
}
