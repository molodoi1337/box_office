#include <Windows.h>
#include <iostream>
#include "boxOffice.h"

using namespace std;

struct products
{
	char* name = new char[255];
	int price;
	int count;

};

void input(products *arr, int& size);
void show(products* arr, int size);
products* plusArr(products* arr, int& size);
products* delArr(products* arr, int& size);
void delArrShow(products* arr, int& size);

int main()
{
	setlocale(LC_ALL, "ru");
	int size = 1;
	products* arr = new products[size];
	cout << "кто ты,воин?Продавец(0) или покупатель(1)?" << endl;
	bool flug = true;
	int a;
	cin >> a;
	if (a == 0) {	
		while (flug)
		 {
			cout << endl;
			cout << "выбирете действие:"<<endl;
			cout << "1 - добавить продукт" << endl;
			cout << "2 - показать список продуктов" << endl;
			cout << "3 - удалить продукт" << endl;
			cout << "4 - перейти за покупателя" << endl;
			int b;
			cin >> b;
			switch (b)
			{
			case 1:
				input(arr, size);
				arr = plusArr(arr, size);
				break;
			case 2:
			
				show(arr,size);
				break;
			case 3:
				arr = delArr(arr,size);
			default:
				break;
			}
		}

	}


}

void input(products *arr,int &size) {	
			cout << "введите название,цену и кол-во по порядку через enter" << endl;
			char* buff = new char[256];
			int a1, a2;
			cin >> buff;
			cin >> a1;
			cin >> a2;
			arr[size - 1].name = buff;
			arr[size - 1].price = a1;
			arr[size - 1].count = a2;
			system("cls");
}
void show(products* arr, int size) {
	for (int i = 0; i < size-1; i++) {
		cout << "номер товара->" << i+1<< endl;
		cout <<"название ->" << arr[i].name << endl;
		cout << "цена ->" << arr[i].price << endl;
		cout << "кол-во ->" << arr[i].count<<endl;
		cout << endl;
	}
}


products* plusArr(products* arr, int& size) {
	size++;	
	products* newArr = new products[size];
	
	for (int i = 0; i < size - 1; i++) {
		strcpy_s(newArr[i].name, 256, arr[i].name);
		newArr[i].price = arr[i].price;
		newArr[i].count = arr[i].count;
		
	}
	delete[] arr; 
	return newArr;
}

products* delArr(products*arr,int& size) {
	
	products* newarr = new products[size-1];
	cout << "какой товар удалить?(номер товара)" << endl;
	show(arr, size);
	int user_choice;
	cin >> user_choice;
	for (int i = 0; i < size; i++) {
		if (user_choice - 1 == i) {
			continue;
		}
		else {
			strcpy_s(newarr[i-user_choice].name, 257, arr[i].name);
			newarr[i - user_choice].price = arr[i].price;
			newarr[i - user_choice].count = arr[i].count;
			
		}
	}
	delete[]arr;
	return newarr;

}

