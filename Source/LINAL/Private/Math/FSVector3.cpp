#include "Math/FSVector3.h"
#include "Math/FSVector4.h"


const FSVector3 FSVector3::Zero(0.0f, 0.0f, 0.0f);

const FSVector3 FSVector3::One(1, 1, 1);

const FSVector3 FSVector3::Up(0.0f, 1.0f, 0.0f);

const FSVector3 FSVector3::Down(0.0f, -1.0f, 0.0f);

const FSVector3 FSVector3::Right(1.0f, 0.f, 0.f);

const FSVector3 FSVector3::Left(-1.0f, 0.f, 0.f);

const FSVector3 FSVector3::Forward(0.0f, 0.0f, 1.f);

const FSVector3 FSVector3::Backward(0.0f, 0.0f, -1.f);



FSVector3::FSVector3(): X(0), Y(0), Z(0){}
FSVector3::FSVector3(const float X, const float Y, const float Z): X(X), Y(Y), Z(Z){}
 
FSVector3 FSVector3::operator+(const FSVector3& V) const
{
	return FSVector3(X + V.X, Y + V.Y, Z + V.Z);
}

FSVector3 FSVector3::operator-(const FSVector3& V) const
{
	return FSVector3(X - V.X, Y - V.Y, Z - V.Z);
}

FSVector3 FSVector3::operator+=(const FSVector3& Value)
{
	*this = *this + Value;
	return *this;
}

FSVector3 FSVector3::operator/(const float& Division) const
{
	return FSVector3(X / Division, Y / Division, Z / Division);
}

FSVector3 FSVector3::operator/=(const float& Division)
{
	*this = *this / Division;
	return *this;
}

FVector FSVector3::ToFVector() const
{
	return FVector(Z, X, Y);
}

FSVector3 FSVector3::ToUEAxis() const
{
	return FSVector3(Y, Z, X);
}

void FSVector3::Normalize()
{
	const double Length = sqrt(this->X * this->X + this->Y * this->Y + this->Z * this->Z);
	this->X             = this->X / Length;
	this->Y             = this->Y / Length;
	this->Z             = this->Z / Length;
}

bool FSVector3::operator!=(const FSVector3& SVector3) const
{
	return !(*this == SVector3);
}

std::string FSVector3::ToString() const
{
	return std::to_string(X) + " " + std::to_string(Y) + " " + std::to_string(Z) ;
}

FSVector3 FSVector3::FromFVector(const FVector& V)
{
	return FSVector3(V.Y, V.Z, V.X);
}

float FSVector3::DotProduct(const FSVector3& L, const FSVector3& R)
{
	return L.X * R.X + L.Y * R.Y + L.Z * R.Z;
}

FSVector3 FSVector3::CrossProduct(const FSVector3& L, const FSVector3& R)
{
	return FSVector3(
		L.Y * R.Z - L.Z * R.Y,
		L.Z * R.X - L.X * R.Z,
		L.X * R.Y - L.Y * R.X);
}


FSVector3 FSVector3::operator-() const
{
	return FSVector3(-X, -Y, -Z);
}

FSVector3 FSVector3::operator*(const FSVector3& V) const
{
	return FSVector3(X * V.X, Y * V.Y, Z * V.Z);
}

FSVector3 FSVector3::operator*(const float& Scalar) const
{
	return FSVector3(X * Scalar, Y * Scalar, Z * Scalar);
}

FSVector3 FSVector3::operator=(const FSVector3& V)
{
	X = V.X;
	Y = V.Y;
	Z = V.Z;
	return *this;
}

FSVector3 FSVector3::operator=(const FSVector4& V)
{
	X = V.X;
	Y = V.Y;
	Z = V.Z;
	return *this;
}

bool FSVector3::operator==(const FSVector3& SVector3) const
{
	return X == SVector3.X && Y == SVector3.Y && Z == SVector3.Z;
}