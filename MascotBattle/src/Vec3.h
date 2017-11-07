#pragma once
// Vec3 Class

#include "./DxLib.h"
#include <string>

struct Vec3 : public VECTOR {
	/*float x;
	float y;
	float z;*/

	Vec3();
	Vec3(float, float, float);
	virtual ~Vec3();

	// method
	float dotProduct(const Vec3&) const; // “àÏ
	Vec3 crossProduct(const Vec3&) const; // ŠOÏ
	float length() const; // ’·‚³
	float lengthSquare() const; // ’·‚³‚Ì2æ
	Vec3 normalized() const; // ³‹K‰»ƒxƒNƒgƒ‹‚ğ•Ô‚·
	std::string getStr() const; // •¶š—ñ‚É‚µ‚Ä•Ô‚·


	Vec3 normalize(); // ³‹K‰»‚·‚é
	void rotateX(float); // X²‰ñ“]
	void rotateY(float); // Y²‰ñ“]
	void rotateZ(float); // Z²‰ñ“]
	void rotateAxis(const Vec3 &, float); // ”CˆÓ²ü‚è‚Ì‰ñ“]

										  // operator
	Vec3 operator+(const Vec3 &) const; // Vec3 + Vec3
	Vec3 operator-(const Vec3 &) const; // Vec3 - Vec3
	Vec3 operator*(float)const;					// Vec3 * float
	Vec3 operator/(float) const;				// Vec3 / float

	Vec3 &operator+=(const Vec3 &); // Vec3 += Vec3
	Vec3 &operator-=(const Vec3 &); // Vec3 -= Vec3
	Vec3 &operator*=(float);				// Vec3 *= float
	Vec3 &operator/=(float);				// Vec3 /= float

	Vec3 operator+() const;	// +Vec3
	Vec3 operator-() const; // -Vec3

	float operator*(const Vec3 &)const; // Vec3 * Vec3

	float &operator[](int); // Vec3[index]
};

// float * Vec3
inline Vec3 operator *(float scale, const Vec3& vec) {
	return{ vec * scale };
}

typedef Vec3 Position3D;

