#include "Vec3.h"
#include <cmath>
#include <vector>

Vec3::Vec3() : VECTOR{ 0, 0, 0 } {
}

Vec3::Vec3(float _x, float _y, float _z) : VECTOR{ _x, _y, _z } {
}

Vec3::~Vec3() {
}

// “àÏ
float Vec3::dotProduct(const Vec3& other) const {
	return *this*other;
}

/*
Vec3 Vec3::crossProduct(const Vec3& other) const {

}
*/

// ’·‚³‚ÌŽæ“¾
float Vec3::length() const {
	return std::sqrtf(this->lengthSquare());
}

// ’·‚³‚Ì2æ‚ÌŽæ“¾
float Vec3::lengthSquare() const {
	return this->x*this->x + this->y*this->y + this->z*this->z;
}

// ³‹K‰»ƒxƒNƒgƒ‹‚ÌŽæ“¾
Vec3 Vec3::normalized() const {
	return *this / this->length();
}

// •¶Žš—ñ‚ÌŽæ“¾
std::string Vec3::getStr() const {
	char text[256]="";
	sprintf_s(text,256, "(%.1f,%.1f,%.1f)", this->x, this->y, this->z);
	return text;
}

// Vec3 + Vec3
Vec3 Vec3::operator+(const Vec3 &other) const {
	return Vec3{ this->x + other.x, this->y + other.y, this->z + other.z };
}

// Vec3 - Vec3
Vec3 Vec3::operator-(const Vec3 &other) const {
	return Vec3{ this->x - other.x, this->y - other.y, this->z - other.z };
}

// Vec3 * float
Vec3 Vec3::operator*(float scale) const {
	return Vec3{ this->x * scale, this->y * scale, this->z * scale };
}
// Vec3 / float
Vec3 Vec3::operator/(float scale) const {
	return Vec3{ this->x / scale, this->y / scale, this->z / scale };
}

// Vec3 += Vec3
Vec3& Vec3::operator+=(const Vec3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

// Vec3 -= Vec3
Vec3& Vec3::operator-=(const Vec3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

// Vec3 *= float
Vec3& Vec3::operator*=(float scale) {
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	return *this;
}

// Vec3 /= float
Vec3& Vec3::operator/=(float scale) {
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;
	return *this;
}

// +Vec3
Vec3 Vec3::operator+()const {
	return *this;
}

// -Vec3
Vec3 Vec3::operator-()const {
	return{ -this->x, -this->y, -this->z };
}

// Vec3 * Vec3
float Vec3::operator*(const Vec3& other) const {
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

// Vec3[0]:x Vec3[1]:y Vec3[2]:z
float& Vec3::operator[](int index) {
	switch (index) {
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	default:
		return this->x;
		break;
	}
	return this->x;
}