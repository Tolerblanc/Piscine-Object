#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {
    if (x < MIN_COORDINATE || x > MAX_COORDINATE || y < MIN_COORDINATE || y > MAX_COORDINATE)
        throw InvalidCoordinateException();
}

const float& Vector2::getX() const { return x; }
const float& Vector2::getY() const { return y; }

bool Vector2::operator<(const Vector2& obj) const
{
    return (x < obj.getX() && y < obj.getY());
}

std::ostream& operator<< (std::ostream& p_os, const Vector2& p_vector2)
{
    p_os << "Vector2(" << p_vector2.getX() << ", " << p_vector2.getY() << ")";
    return p_os;
}

const char * Vector2::InvalidCoordinateException::what(void) const throw()
{
    return ("Invalid Coordinate");
}
