#pragma once

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

/**
 * \brief OBJ文件的点面数据
 */
class Obj
{
public:
	using Face = std::vector<std::vector<double>>;
	using Faces = std::vector<Face>;

	void readFromFile(const QString& path);
	void translate(double x, double y, double z);
	void scale(double x, double y, double z);
	void rotateY(double theta);
	Faces& getFaces();
	void rotateX(double x);
	double x_max, x_min, y_max, y_min,z_max,z_min;
private:
	std::vector<matrix<double>> vertices;
	std::vector<std::vector<int>> indices_of_faces;
	Faces vertices_of_faces;
};
