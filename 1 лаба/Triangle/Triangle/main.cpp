// Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"

unsigned getSideLength(const char * numb)
{
	float side = atof (numb);
	return (side > 0 ? side : 0);
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc == 4)
	{
		CTriangle triangle(getSideLength(argv[1]), getSideLength(argv[2]), getSideLength(argv[3]));
		std::cout << triangle.getType();
	}
	else
	{
		std::cout << "Укажите длины сторон в качестве параметров. Формат ввода: triangle.exe a b c";
	}
    return 0;
}

