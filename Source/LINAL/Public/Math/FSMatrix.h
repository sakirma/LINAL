#pragma once

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

	FSMatrix();

	FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W);
	FSMatrix(const FSVector4& X, const FSVector4& Y, const FSVector4& Z, const FSVector4& W);

	FSMatrix operator*(const FSMatrix& ROther) const;
	FSMatrix operator*=(const FSMatrix& ROther);
	FSMatrix operator*(const float& Scalar) const;
	FSMatrix operator*=(const float& Scalar);

	bool operator==(const FSMatrix& MOther);
	
	FSVector4 TransformVector(const FSVector4& Vector) const;

	static FSMatrix Transform(const FSVector3& Vector);
	static FSMatrix Scale(const FSVector3& Scale);
	
	static FSMatrix GetRotationX(double AngleXDegrees);
	static FSMatrix GetRotationY(double AngleYDegrees);
	static FSMatrix GetRotationZ(double AngleZDegrees);

	static FSMatrix GetRotationM1(const FSVector3& RotationAxis);
	static FSMatrix GetRotationM2(const FSVector3& RotationAxis);
	static FSMatrix GetRotationM4(const FSVector3& RotationAxis);
	static FSMatrix GetRotationM5(const FSVector3& RotationAxis);
};
