#pragma once

struct FSVector3;

struct FSVector4
{
public:
	float X, Y, Z, W;

	FSVector4();
	
	FSVector4(float X, float Y, float Z, float W);
	
	FSVector4(const FSVector3& InVector, float W = 1.0f);

public:
	FSVector4 operator+(const FSVector4& V) const;
	
	FSVector4 operator-(const FSVector4& V) const;
	
	FSVector4 operator*(const FSVector4& V) const;
	
	FSVector4 operator*(const float& Scale) const;

	FSVector4 operator=(const FSVector3& V3);
};