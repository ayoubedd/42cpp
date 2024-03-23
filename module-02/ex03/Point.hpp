#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"
#include <string>

class Point {
public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &src);
  Point &operator=(const Point &src);
  ~Point(void);

  Fixed getX(void) const;
  Fixed getY(void) const;

private:
  const Fixed _x;
  const Fixed _y;
};

std::ostream &operator<<(std::ostream &stream, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // !__POINT_HPP__
