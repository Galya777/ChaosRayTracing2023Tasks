#include <iostream>
#include "../Homework2/v3.h"
using namespace std;
//Task 1
class Triangle {
public:
	my_v3 v0;
	my_v3 v1;
	my_v3 v2;

	Triangle(const my_v3& v0, const my_v3& v1, const my_v3& v2) : v0(v0), v1(v1), v2(v2) {}
	my_v3 getNormal() {
		my_v3 normal = (v1 - v0).crossProduct(v2 - v0);
		normal.normalize();
		return normal;
	};
	float getArea() {
		float p = (v0.len() + v1.len() + v2.len()) / 2;
		return sqrt(p*(p-v0.len())* (p - v1.len())* (p - v2.len()));
	}
};
int main()
{
	//Task2 
	my_v3 dotOne(3.5, 0, 0);
	std::cout<< dotOne.dotProduct(my_v3{ 1.75, 3.5, 0 })<<endl;
	my_v3 dotTwo(3, -3, 1);
	std::cout << dotTwo.dotProduct(my_v3{ 4, 9, 3 })<<endl;
	my_v3 ab1(3, -3, 1); my_v3 bc1(4, 9, 3);
	std::cout << abs(ab1.dotProduct(bc1))<<endl;
	my_v3 ab2(3, -3, 1); my_v3 bc2(-12, 12, -4);
	std::cout << abs(ab2.dotProduct(bc2)) << endl;
	//Task 3
	Triangle t1( my_v3( - 1.75, -1.75, -3 ), my_v3(1.75, -1.75, -3), my_v3(0, 1.75, -3));
	std::cout << t1.getNormal().get_x()<<" "<< t1.getNormal().get_y()<<" "<< t1.getNormal().get_z() << endl;
	Triangle t2(my_v3(0, 0, -1), my_v3(1, 0, 1), 	my_v3(-1, 0, 1));
	std::cout << t2.getNormal().get_x() << " " << t2.getNormal().get_y() << " " << t2.getNormal().get_z() << endl;
	Triangle t3(my_v3(0.56, 1.11, 1.23),my_v3(0.44, -2.368, -0.54),my_v3(-1.56, 0.15, -1.92));
	std::cout << t3.getNormal().get_x() << " " << t3.getNormal().get_y() << " " << t3.getNormal().get_z() << endl;
	std::cout << t1.getArea() << " " << t2.getArea() << " " << t3.getArea() << endl;

	return 0;
}
