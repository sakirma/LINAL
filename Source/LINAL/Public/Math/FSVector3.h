#pragma once
#include <string>


struct FSVector4;

struct FSVector3
{
public:
	float X, Y, Z;

	FSVector3();

	FSVector3(float X, float Y, float Z);

public:
	FSVector3 operator+(const FSVector3& V) const;

	FSVector3 operator-(const FSVector3& V) const;

	FSVector3 operator-() const;

	FSVector3 operator*(const FSVector3& V) const;

	FSVector3 operator*(const float& Scalar) const;

	FSVector3 operator=(const FSVector3& V);
	
	FSVector3 operator=(const FSVector4& V);

	bool      operator==(const FSVector3& SVector3) const;
	FSVector3 operator+=(const FSVector3& Value);

	FSVector3 operator/(const float& Division) const;
	FSVector3 operator/=(const float& Division);

	FVector   ToFVector() const;
	FSVector3 ToUEAxis() const;

	void        Normalize();
	bool        operator!=(const FSVector3& SVector3) const;
	std::string ToString() const;

	static FSVector3 FromFVector(const FVector& V);

	static float DotProduct(const FSVector3& L, const FSVector3& R);

	static FSVector3 CrossProduct(const FSVector3& L, const FSVector3& R);

public:
	static const FSVector3 Zero;

	static const FSVector3 One;

	static const FSVector3 Up;

	static const FSVector3 Down;

	static const FSVector3 Right;

	static const FSVector3 Left;

	static const FSVector3 Forward;

	static const FSVector3 Backward;
};

