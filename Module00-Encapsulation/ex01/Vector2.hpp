#pragma once

#define MIN_COORDINATE 0
#define MAX_COORDINATE 10

#include <exception>

class Graph;

class Vector2
{
private:
    float x;
    float y;
    friend class Graph;

    Vector2(float x, float y);
    Vector2();
    Vector2(const Vector2& p_vector2);
    Vector2& operator=(const Vector2& p_vector2);

public:
    ~Vector2();
    const float& getX() const;
    const float& getY() const;
    bool	operator<(const Fixed& obj) const;

    class InvalidCoordinateException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };
};

std::ostream& operator<< (std::ostream& p_os, const Account& p_account);