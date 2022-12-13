#pragma once

#include "NIQuaternion.h"
#include "NIVector3.h"

namespace NI {
	struct Matrix33 {
		Vector3 m0;
		Vector3 m1;
		Vector3 m2;

		Matrix33();
		Matrix33(const Vector3& outerA, const Vector3& outerB);
		Matrix33(Vector3* m0, Vector3* m1, Vector3* m2);
		Matrix33(float m0x, float m0y, float m0z, float m1x, float m1y, float m1z, float m2x, float m2y, float m2z);
		Matrix33(const Quaternion& fromQuaternion);

		//
		// Basic operators.
		//

		bool operator==(const Matrix33& matrix);
		bool operator!=(const Matrix33& matrix);
		Matrix33 operator+(const Matrix33& matrix);
		Matrix33 operator-(const Matrix33& matrix);
		Matrix33 operator*(const Matrix33& matrix);
		Vector3 operator*(const Vector3& vector);
		Matrix33 operator*(float scalar);

		friend std::ostream& operator<<(std::ostream& str, const Matrix33& matrix);
		std::string toString() const;
		std::string toJson() const;

		//
		// Set the matrix to specific useful values.
		//

		Matrix33 copy() const;

		void toZero();
		void toIdentity();
		void toRotationX(float x);
		void toRotationY(float y);
		void toRotationZ(float z);
		void toRotation(float angle, float x, float y, float z);

		//
		// Other related helper functions.
		//

		Matrix33 transpose();

		Matrix33 invert() const;
		bool invert(Matrix33* out_matrix) const;
#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		std::tuple<Matrix33, bool> invert_lua() const;
#endif

		void fromEulerXYZ(float x, float y, float z);
		bool toEulerXYZ(Vector3* vector) const;
		bool toEulerXYZ(float* x, float* y, float* z) const;
#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		std::tuple<Vector3, bool> toEulerXYZ_lua() const;
#endif

		bool toEulerZYX(Vector3* vector) const;
		bool toEulerZYX(float* x, float* y, float* z) const;
#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		std::tuple<Vector3, bool> toEulerZYX_lua() const;
#endif

		NI::Quaternion toQuaternion();

		bool reorthogonalize();

		//
		//
		//

		static constexpr auto IdentityMatrix = reinterpret_cast<Matrix33*>(0x0);

	};
	static_assert(sizeof(Matrix33) == 0x24, "TES3::Matrix33 failed size validation");
}
