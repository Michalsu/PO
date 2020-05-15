#ifndef VEC2_H_
#define VEC2_H_
#include <cmath>

class Vec2 {
public:
	Vec2();
	Vec2(double x_, double y_);

	void Dodaj(Vec2 a);
	void Odejmij(Vec2 a);
	void Pomnoz(Vec2 a, float b);
	float Modul();

	float x,y;
};

#endif /* VEC2_H_ */