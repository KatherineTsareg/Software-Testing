// Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

bool isUint(char * numb)
{
	stringstream ss;
	ss << numb;
	string numbString;
	ss >> numbString;
	boost::replace_all(numbString, ".", ",");
	if (all_of(numbString.begin(), numbString.end(), [&](auto x){
		return ((int(x) > 47) && (int(x) < 58) || (int(x) == 44) && (numbString.length() > 1)); }))
	{
		return true;
	}
	return false;
}

float getSideLength(char * numb)
{
	stringstream ss;
	ss << numb;
	string numbString;
	ss >> numbString;
	boost::replace_all(numbString, ".", ",");
	return stof(numbString);
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc == 4 && isUint(argv[1]) && isUint(argv[2]) && isUint(argv[3]))
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

