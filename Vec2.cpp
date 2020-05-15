#include "Vec2.h"




Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(double x_, double y_) : x(x_), y(y_){
x=x_;
y=y_;
}

void Vec2::Dodaj(Vec2 a) {
}

void Vec2::Odejmij(Vec2 a) {
}

void Vec2::Pomnoz(Vec2 a, float b) {
}

float Vec2::Modul() {
	float modul= sqrt(x*x+y*y);
	return modul;
}
