#include "Point.hpp"
#include <ostream>

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {}

Point& Point::operator=(const Point &src)  {
  (void)src;
  return *this;
}


Point::~Point(void) {

}

Fixed Point::getX(void) const {
  return _x;
}

Fixed Point::getY(void) const {
  return _y;
}

std::ostream& operator<<(std::ostream& stream, const Point& point) {
  stream << "Point: x -> " << point.getX() << ", y -> " << point.getY();
  return stream;
}

