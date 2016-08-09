#include "matrix4d.h"

#include <iostream>

namespace zacky {
namespace math {



Matrix4d::Matrix4d()
{
	matrix_ = Eigen::Matrix4d::Zero(4, 4);
}



Matrix4d::Matrix4d(double diagonal)
{
	matrix_ = Eigen::Matrix4d::Identity(4, 4)*diagonal;
}


Matrix4d::Matrix4d(double(&carr)[16])
{
	matrix_ = Eigen::Matrix4d(carr);
}

Matrix4d::Matrix4d(std::array<double, 16> arr)
{
	matrix_ = Eigen::Matrix4d(&arr.front());
}

std::array<double, 16> Matrix4d::getArray() const
{
	std::array<double, 16> arr;
	Eigen::Map<Eigen::Matrix4d>(&arr.front(), 4, 4) = matrix_;
	return arr;
}


//FRIENDS
//=================

Matrix4d operator+(const Matrix4d & mat1, const Matrix4d & mat2)
{
	Matrix4d matrix;
	matrix.matrix_ = mat1.matrix_ + mat2.matrix_;
	return matrix;
}

Matrix4d operator- (const Matrix4d& mat1, const Matrix4d& mat2)
{
	Matrix4d matrix;
	matrix.matrix_ = mat1.matrix_ - mat2.matrix_;
	return matrix;
}
Matrix4d operator* (const Matrix4d& mat1, const Matrix4d& mat2)
{
	Matrix4d matrix;
	matrix.matrix_ = mat1.matrix_ * mat2.matrix_;
	return matrix;
}

Matrix4d operator* (double scalar, const Matrix4d& mat)
{
	Matrix4d matrix;
	matrix.matrix_ = scalar * mat.matrix_;
	return matrix;
}
Matrix4d operator/ (const Matrix4d& mat, double scalar)
{
	Matrix4d matrix;
	matrix.matrix_ = mat.matrix_/scalar;
	return matrix;
}

bool operator== (const Matrix4d& mat1, const Matrix4d& mat2)
{
	return mat1.matrix_ == mat2.matrix_;
}
bool operator!= (const Matrix4d& mat1, const Matrix4d& mat2)
{
	return !(mat1 == mat2);
}


std::ostream& operator<<(std::ostream& os, const Matrix4d& mat)
{
	os << mat.matrix_;
	return os;
}

//maybe make void?
ArrD16 & operator>> (const Matrix4d& matrix, ArrD16 &arr)
{
	Eigen::Map<Eigen::Matrix4d>(arr, 4, 4) = matrix.matrix_;
	return arr;
}

std::array<double, 16> operator >> (const Matrix4d & matrix, std::array<double, 16> arr)
{
	Eigen::Map<Eigen::Matrix4d>(&arr.front(), 4, 4) = matrix.matrix_;
	return arr;
}


//Maybe make void?
Matrix4d& operator<< (Matrix4d& matrix, ArrD16 &arr)
{
	matrix.matrix_ = Eigen::Map<Eigen::Matrix4d>(arr, 4, 4);
	return matrix;
}

Matrix4d & operator<<(Matrix4d & matrix, std::array<double, 16> arr)
{
	matrix.matrix_ = Eigen::Map<Eigen::Matrix4d>(&arr.front(), 4, 4);
	return matrix;
}

}// namespace math
}// namespace zacky