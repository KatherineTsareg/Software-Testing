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
		nameOfType = "�� �����������";
		break;
	case (SIMPLE):
		nameOfType = "�������";
		break;
	case(ISOSCELES):
		nameOfType = "��������������";
		break;
	case(EQUILATERAL):
		nameOfType = "��������������";
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
	if (exist) // �������� �� ������������� ������������
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
