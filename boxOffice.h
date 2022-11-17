#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class boxOffice
{
	char* name = new char[255];
	int price, count;

public:
	boxOffice(char* name,int price,int count) {
		strcpy_s(boxOffice::name,255,name);
		boxOffice::price = price;
		boxOffice::count = count;
	}

	

};

