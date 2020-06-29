#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	int x;
	int y;
	// ”äŠr‰‰ŽZŽq
	Vector2& operator=(const Vector2& vec);
	int& operator[](int no);
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator+=(int k);
	Vector2& operator*=(int k);
	Vector2& operator/=(int k);
	Vector2 operator+()const;
	Vector2 operator-()const;


	bool operator==(const Vector2& vec)const;
	bool operator!=(const Vector2& vec)const;
	bool operator<=(const Vector2& vec)const;
	bool operator<(const Vector2& vec)const;



};

Vector2 operator+(const Vector2& u, int v);
Vector2 operator-(const Vector2& u, int v);
Vector2 operator*(const Vector2& u, int v);
Vector2 operator/(const Vector2& u, int v);
Vector2 operator*(const int& u, Vector2& v);
Vector2 operator%(const Vector2& u, int v);
Vector2 operator+(const Vector2& u, int v);
Vector2 operator+(const Vector2& u, Vector2 v);
Vector2 operator-(const Vector2& u, Vector2 v);
//Vector2 operator+(const Vector2& u, int v);
//Vector2 operator+(const Vector2& u, int v);
//Vector2 operator+(const Vector2& u, int v);
//Vector2 operator+(const Vector2& u, int v);
//Vector2 operator+(const Vector2& u, int v);