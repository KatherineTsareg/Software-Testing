#pragma once
#include <string>

class CTriangle
{
public:
	CTriangle(unsigned a, unsigned b, unsigned c);
	std::string getType();
	~CTriangle();
private:
	unsigned a, b, c;
	const enum TYPE { NOTEXIST, SIMPLE, ISOSCELES, EQUILATERAL};
	TYPE type = NOTEXIST;
	void determineTheType();
};

