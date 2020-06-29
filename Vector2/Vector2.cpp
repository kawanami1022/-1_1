#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y):x(x),y(y)
{
}

Vector2::~Vector2()
{
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;

	// TODO: return ステートメントをここに挿入します
	return (*this);
}

int& Vector2::operator[](int no)
{
	if (no==0)
	{
		return x;
	}
	else if(no==1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	x += vec.x;
	y += vec.y;
	return  (*this);
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	x -= vec.x;
	y -= vec.y;
	// TODO: return ステートメントをここに挿入します
	return (*this);

}

Vector2& Vector2::operator+=(int k)
{
	// TODO: return ステートメントをここに挿入します
	x += k;
	y += k;
	return (*this);
}

Vector2& Vector2::operator*=(int k)
{
	x *= k;
	y *= k;
	// TODO: return ステートメントをここに挿入します
	return (*this);
}

Vector2& Vector2::operator/=(int k)
{
	x /= k;
	y /= k;
	// TODO: return ステートメントをここに挿入します
	return *this;
}

Vector2 Vector2::operator+() const
{
	// TODO: return ステートメントをここに挿入します
	return (*this);
}

Vector2 Vector2::operator-() const
{
	// TODO: return ステートメントをここに挿入します
	return {-this->x, -this->y};
}

bool Vector2::operator==(const Vector2& vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool Vector2::operator!=(const Vector2& vec) const
{
	return ((this->x != vec.x) && (this->y != vec.y));
}

bool Vector2::operator<=(const Vector2& vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));;
}

bool Vector2::operator<(const Vector2& vec) const
{
	return ((this->x < vec.x) && (this->y <vec.y));;
}

Vector2 operator+(const Vector2& u, int v)
{
	return {u.x+v,u.y + v };
}


Vector2 operator-(const Vector2& u, int v)
{
	return { u.x - v,u.y - v };;
}

Vector2 operator*(const Vector2& u, int v)
{
	return { u.x * v,u.y * v };
}

Vector2 operator/(const Vector2& u, int v)
{

	return { u.x / v,u.y / v };
}

Vector2 operator*(const int& u, Vector2 v)
{

	return { u * v.x,u * v.y };
}

Vector2 operator%(const Vector2& u, int v)
{
	return { u.x % v,u.y % v };
}

Vector2 operator+(const Vector2& u, Vector2 v)
{
	return { u.x + v.x,u.y + v.y };
}

Vector2 operator-(const Vector2& u, Vector2 v)
{
	return { u.x - v.x,u.y - v.y };
}



