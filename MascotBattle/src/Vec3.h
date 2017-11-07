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
	float dotProduct(const Vec3&) const; // ����
	Vec3 crossProduct(const Vec3&) const; // �O��
	float length() const; // ����
	float lengthSquare() const; // ������2��
	Vec3 normalized() const; // ���K���x�N�g����Ԃ�
	std::string getStr() const; // ������ɂ��ĕԂ�


	Vec3 normalize(); // ���K������
	void rotateX(float); // X����]
	void rotateY(float); // Y����]
	void rotateZ(float); // Z����]
	void rotateAxis(const Vec3 &, float); // �C�ӎ�����̉�]

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

