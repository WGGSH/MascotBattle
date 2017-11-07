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
	float dotProduct(const Vec3&) const; // 内積
	Vec3 crossProduct(const Vec3&) const; // 外積
	float length() const; // 長さ
	float lengthSquare() const; // 長さの2乗
	Vec3 normalized() const; // 正規化ベクトルを返す
	std::string getStr() const; // 文字列にして返す


	Vec3 normalize(); // 正規化する
	void rotateX(float); // X軸回転
	void rotateY(float); // Y軸回転
	void rotateZ(float); // Z軸回転
	void rotateAxis(const Vec3 &, float); // 任意軸周りの回転

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

