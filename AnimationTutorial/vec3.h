#ifndef _H_VEC3_
#define _H_VEC3_

#define VEC3_EPSILON 0.000001f

struct vec3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float v[3];
	};
	inline vec3() : x(0.0f), y(0.0f), z(0.0f) { }
	inline vec3(float _x, float _y, float _z) :
		x(_x), y(_y), z(_z) { }
	inline vec3(float* fv) :
		x(fv[0]), y(fv[1]), z(fv[2]) { }
};

// Addition
vec3 operator+(const vec3& l, const vec3& r);
// Subtraction
vec3 operator-(const vec3& l, const vec3& r);
// Scaling
vec3 operator*(const vec3& v, float f);
// Normal multiplication
vec3 operator*(const vec3& l, const vec3& r);
// Comparison
bool operator==(const vec3& l, const vec3& r);
bool operator!=(const vec3& l, const vec3& r);
// Dot product
float dot(const vec3& l, const vec3& r);
// Square length function
float lenSq(const vec3& v);
// Lenght function
float len(const vec3& v);
// Normalize input vector
void normalize(vec3 &v);
// Normalize vector by not modifying the input
vec3 normalized(const vec3& v);
// Get angle between vectors
float angle(const vec3& l, const vec3& r);
// Projection
vec3 project(const vec3& a, const vec3& b);
// Rejection
vec3 reject(const vec3& a, const vec3& b);
// Reflection
vec3 reflect(const vec3& a, const vec3& b);
// Cross product
vec3 cross(const vec3& l, const vec3& r);
// Linear interpolation, shortest path
vec3 lerp(const vec3& s, const vec3& e, float t);
// Spherical linear interpolation, shortest arc
vec3 slerp(const vec3& s, const vec3& e, float t);
// Normalized linear interpolation, not continous in velocity, approximates slerp
vec3 nlerp(const vec3& s, const vec3& e, float t);
#endif