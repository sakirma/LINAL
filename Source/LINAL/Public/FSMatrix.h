#pragma once


#include <cmath>

struct FSVector3;
struct FSVector4;

struct FSMatrix
{
public:
	union
	{
		float Matrix[4][4];
		float M[4 * 4];
	};

	inline FSMatrix();

	inline FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W);
	inline FSMatrix(const FSVector4& X, const FSVector4& Y, const FSVector4& Z, const FSVector4& W);

	inline FSMatrix operator*(const FSMatrix& ROther) const;
	inline FSMatrix operator*=(const FSMatrix& ROther);
	inline FSMatrix operator*(const float& Scalar) const;
	inline FSMatrix operator*=(const float& Scalar);

	
	inline bool operator==(const FSMatrix& MOther);
	
	
	inline FSVector4 TransformVector(const FSVector4& Vector) const;

	static inline FSMatrix Transform(const FSVector3& Vector);
	static inline FSMatrix Scale(const FSVector3& Scale);
	
	static inline FSMatrix GetRotationX(double AngleXDegrees);
	static inline FSMatrix GetRotationY(double AngleYDegrees);
	static inline FSMatrix GetRotationZ(double AngleZDegrees);

	static inline FSMatrix GetRotationM1(const FSVector3& RotationAxis);
	static inline FSMatrix GetRotationM2(const FSVector3& RotationAxis);
	static inline FSMatrix GetRotationM4(const FSVector3& RotationAxis);
	static inline FSMatrix GetRotationM5(const FSVector3& RotationAxis);
};

#include "FSMatrix.inl"
