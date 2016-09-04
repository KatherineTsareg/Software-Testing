#pragma once
#include <string>

class CTriangle
{
public:
	CTriangle(float a, float b, float c);
	std::string getType();
	~CTriangle();
private:
	float a, b, c;
	const enum TYPE { NOTEXIST, SIMPLE, ISOSCELES, EQUILATERAL};
	TYPE type = NOTEXIST;
	void determineTheType();
};

