#include <iostream>
#include <cmath>
#include <conio.h>
#include <iomanip>

using namespace std;

double f(double x) // данная функция
{
	return 8 * sin(x) - pow(x, 2);
}

double f1(double x) // первая производная данной функции
{
	return 8 * cos(x) - 2 * x;
}

double f2(double x) // вторая производная данной функции
{
	return -8 * sin(x) - 2;
}

void half(double a, double b) // метод половинного деления
{
	double e, c;
	int i = 0;
	e = 0.0001; // точность
	cout << setw(3) << "n" << setw(12) << "a" << setw(12) << "c" << setw(12) << "b" << setw(12) << "F(a)" << setw(12) << "F(c)" << setw(12) << "F(b)" << setw(12) << endl;
	c = (a + b) / 2;
	cout << setw(3) << i << setw(12) << a << setw(12) << c << setw(12) << b << setw(12) << f(a) << setw(12) << f(c) << setw(12) << f(b) << endl;
	while (fabs(b - a) > 2*e) { 
		i++;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
		c = (a + b) / 2;
		cout << setw(3) << i << setw(12) << a << setw(12) << c << setw(12) << b << setw(12) << f(a) << setw(12) << f(c) << setw(12) << f(b) << endl;
	}
	cout << 
	system("pause");
}

void chord(double a, double b) {
	double e, x, da = 0, db = 0;
	int i = 0;
	e = 0.0001;
	x = (b + a) / 2.0;
	cout << "Выражение F' * F'' имеет знак ";
	if (f1(x) * f2(x) > 0) {
		cout << "+" << endl;
	}
	else if (f1(x) * f2(x) < 0) {
		cout << "-" << endl;
	}
	cout << "Уравнение:   8 * sin(x) - x * x" << endl;
	cout << "Производная: 8 * cos(x) - 2 * x" << endl;
	cout << setw(3) << "n" << setw(12) << "a" << setw(12) << "b" << setw(12) << "b - a" << setw(12) << "F(a) +" << setw(12) << "F(b) -" << setw(12) << "da" << setw(12) << "db" << endl;
	while (fabs(b - a) > 2 * e) {
		b = b + db;
		a = a + da;
		cout << setw(3) << i << setw(12) << a << setw(12) << b << setw(12) << b - a << setw(12) << f(a) << setw(12) << f(b);
		
		if (f1(x) * f2(x) > 0) {
			da = -f(a) * (b - a) / (f(b) - f(a));
			db = -f(b) / f1(b);
		}
		else if (f1(x) * f2(x) < 0) {
			da = -f(a) / f1(a);
			db = -f(b) * (b - a) / (f(b) - f(a));
		}
		else {
			cout << "WTF";
		}
		i++;
		cout << setw(12) << fixed << da << setw(12) << fixed << db << endl;
	} 
	cout << "Ответ" << endl;
	cout << "x = " << (b + a) / 2.0 << " " << "Погрешность dx < 0,00005" << endl;
	cout << "Проверка     F(x*) = F(" << (b + a) / 2.0 << ") = "  << f((b + a) / 2.0) << endl;
	system("pause");
}

double bruh(){
	return 2.5;
}

void main() {
	setlocale(0, "");
	int option = 1;
	double a, b;
	a = 2.25;	 //границы отрезка
	b = 2.5;
	while (option != 48) {
		cout << "1. Метод половинного деления" << endl << "2. Метод хорд и касательных";
		option = _getch();
		switch (option) {
		case '1':
			system("cls");
			half(a, b);
			system("cls");
			break;
		case '2':
			system("cls");
			chord(a, b);
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
}