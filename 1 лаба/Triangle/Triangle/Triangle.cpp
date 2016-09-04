#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(float a, float b, float c)
	:a(a)
	,b(b)
	,c(c)
{
}

std::string CTriangle::getType()
{
	determineTheType();
	std::string nameOfType;
	switch (type)
	{
	case (NOTEXIST):
		nameOfType = "Не треугольник";
		break;
	case (SIMPLE):
		nameOfType = "Простой";
		break;
	case(ISOSCELES):
		nameOfType = "Равнобедренный";
		break;
	case(EQUILATERAL):
		nameOfType = "Равносторонний";
		break;
	}
	return nameOfType;
}

CTriangle::~CTriangle()
{
}

void CTriangle::determineTheType()
{
	bool exist = ((a + b) > c) && ((a + c) > b) && ((b + c) > a);
	if (exist) // Проверка на существование треугольника
	{
		if ((a == b) && (b == c) && (a == c))
		{
			type = EQUILATERAL;
		}
		else if ((a == b) || (b == c) || (a == c))
		{
			type = ISOSCELES;
		}
		else
		{
			type = SIMPLE;
		}
	}
	else
	{
		type = NOTEXIST;
	}
}
