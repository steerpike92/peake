#pragma once

#include <Eigen\Dense>

#include <iostream>
#include <array>

namespace peake {
namespace math {

typedef double ArrD16[16];


class Matrix4d {
public:

	Matrix4d();
	Matrix4d(double diagonal);
	Matrix4d(double(&carr)[16]);
	Matrix4d(std::array<double,16> arr);

	~Matrix4d() = default;

	std::array<double, 16> getArray() const;





	//FRIENDS
	friend Matrix4d operator+ (const Matrix4d& mat1, const Matrix4d& mat2);
	friend Matrix4d operator- (const Matrix4d& mat1, const Matrix4d& mat2);
	friend Matrix4d operator* (const Matrix4d& mat1, const Matrix4d& mat2);
	friend Matrix4d operator* (double scalar, const Matrix4d& mat);
	friend Matrix4d operator/ (const Matrix4d& mat, double scalar);
	friend bool operator== (const Matrix4d& mat1, const Matrix4d& mat2);
	friend bool operator!= (const Matrix4d& mat1, const Matrix4d& mat2);

	friend ArrD16& operator>> (const Matrix4d& matrix, ArrD16& arr);
	friend std::array<double,16> operator>> (const Matrix4d& matrix, std::array<double,16>);
	friend Matrix4d& operator<< (Matrix4d& matrix, ArrD16 &arr);
	friend Matrix4d& operator<< (Matrix4d& matrix, std::array<double, 16>);

	friend std::ostream& operator<< (std::ostream& os, const Matrix4d &mat);



private:
	Eigen::Matrix4d matrix_;

	
};



}// namespace math
}// namespace peake
