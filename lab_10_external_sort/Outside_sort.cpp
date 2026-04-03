#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

string FF1 = "F1.txt";
string FF2 = "F2.txt";

void print(string a)
{
	ifstream fin(a);
	int t;
	while (fin >> t)
	{
		fin >> t;
		cout << t<<" ";
	}
	cout << endl;
	fin.close();
}

void marge(string a)
{
	
	bool fl = 1,fl2=1;
	int n1=0, n2 = 0;
	while (fl||fl2)
	{
		ifstream fin(a);
		n1 = 0;
		n2 = 0;
		ofstream F1(FF1), F2(FF2);
		int x1,x2;
		n1++;
		fin >> x1;
		F1 << x1 << ' ';
		fin >> x2;
		while (x1 <= x2 && !fin.eof())
		{
			F1 << x2 << ' ';
			x1 = x2;
			fin >> x2;
			n1++;
		}
		if (fin.eof() && x2<x1)
		{
			F2 << x2 << ' ';
			n2++;
		}
		if (!fin.eof())
		{
			F2 << x2 << ' ';
			x1=x2;
			fin >> x2;
			n2++;
			while (x1 <= x2 && !fin.eof())
			{
				F2 << x2 << ' ';
				x1 = x2;
				fin >> x2;
				n2++;
			}
			if (fin.eof() && x2 > x1)
			{
				F2 << x2 << ' ';
				n2++;
			}
		}
		fl = !fin.eof()||fl2;
		fl2 = !fin.eof();
		F1.close();
		F2.close();
		fin.close();
		print(FF1);
		print(FF2);
		print("inp.txt");
		cout << endl;

		ifstream F11(FF1), F22(FF2);
		fstream fout(a);
		fout.seekg(0, ios::beg);
		int p1,p2,i=0, j=0;
		F11 >> p1;
		F22 >> p2;
		while (i < n1 && j < n2) {
			if (p1 < p2)
			{
				fout <<p1<<' ';
				F11 >> p1;
				i++;
			}
			else
			{
				fout << p2 << ' ';;
				F22 >> p2;
				j++;
			}
		}
		while (i < n1)
		{
			fout << p1 << ' ';
			F11 >> p1;
			i++;
		}
		while (j < n2)
		{
			fout << p2 << ' ';;
			F22 >> p2;
			j++;
		}
		
	}
}

void marge_mod(string a)
{
	bool fl = 1;
	while (fl)
	{
		ifstream input(a);
		ofstream run1(FF1);
		ofstream run2(FF2);
		int current, previous;
		bool writeToRun1 = true;
		bool fl2 = 1;
		if (input >> previous) {
	
			run1 << previous << " ";
			while (input >> current) {
				if (current < previous) {
					writeToRun1 = !writeToRun1;
					if (fl2 == 0)
					{
						break;
					}
					fl2 = 0;
				}
				if (writeToRun1) {
					run1 << current << " ";
				}
				else {
					run2 << current << " ";
				}
				previous = current;
			}
		}

		input.close();
		run1.close();
		run2.close();
		print(FF1);
		print(FF2);
		print(a);
		ifstream F11(FF1), F22(FF2);
		fstream fout(a);
		fout.seekg(0, ios::beg);

		int val1, val2;
		bool hasVal1 = (bool)(F11 >> val1);
		bool hasVal2 = (bool)(F22 >> val2);
		while (hasVal1 && hasVal2) {
			if (val1 <= val2) {
				fout << val1 << " ";
				hasVal1 = (bool)(F11 >> val1);
			}
			else {
				fout << val2 << " ";
				hasVal2 = (bool)(F22 >> val2);
			}
		}
		while (hasVal1) {
			fout << val1 << " ";
			hasVal1 = (bool)(F11 >> val1);
		}

		while (hasVal2) {
			fout << val2 << " ";
			hasVal2 = (bool)(F22 >> val2);
		}
		fout.close();
		F11.close();
		F22.close();
		ifstream pr(FF2);
		if (pr.peek() == EOF)
		{
			fl = 0;
		}
		pr.close();

	}
}


void recovery(string a, string f1, string f2)
{
	ofstream fout(a);
	ifstream fin1(f1 + ".txt");
	ifstream fin2(f2 + ".txt");
	int val1, val2;
	bool hasVal1 = (bool)(fin1 >> val1);
	bool hasVal2 = (bool)(fin2 >> val2);
	while (hasVal1 && hasVal2) {
		if (val1 <= val2) {
			fout << val1 << " ";
			hasVal1 = (bool)(fin1 >> val1);
		}
		else {
			fout << val2 << " ";
			hasVal2 = (bool)(fin2 >> val2);
		}
	}
	while (hasVal1) {
		fout << val1 << " ";
		hasVal1 = (bool)(fin1 >> val1);
	}

	while (hasVal2) {
		fout << val2 << " ";
		hasVal2 = (bool)(fin2 >> val2);
	}
	fout.close();
	fin1.close();
	fin2.close();
	remove((f1+".txt").c_str());
	remove((f2 + ".txt").c_str());
}



void marge_bal(string a, int n)
{
	if (n == 1)
	{
		return;
	}
	string main = a + ".txt";
	ifstream fin(main);
	string F1 = a + "_" + to_string(n) + "_1";
	string F2 = a + "_" + to_string(n) + "_2";
	ofstream fout1(F1 + ".txt");
	ofstream fout2(F2 + ".txt");
	for (int i = 0; i < n / 2; i++)
	{
		int t;
		fin >> t;
		fout1 << t<<" ";
	}
	for (int i = n / 2;i<n; i++)
	{
		int t;
		fin >> t;
		fout2 << t << " ";
	}
	fin.close();
	fout1.close();
	fout2.close();
	print(F1);
	print(F2);
	marge_bal(F1, (n / 2));
	marge_bal(F2, n-(n/2));
	recovery(main, F1, F2);
}

int fib(int n)
{
	if (n == 1||n==0)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);

}

void print_zpt(ofstream& fout, int n)
{
	for (int i = 0; i < n; i++)
	{
		fout << ", ";
	}
}

void recovery(ifstream& fin1, ifstream& fin2, ofstream& fout)
{
	int val1, val2;
	string str1, str2;
	fin1 >> str1;
	fin2 >> str2;
	//cout << fin2.get();
	bool hasVal1 = 1;
	bool hasVal2 = 1;
	if (str1 == "," || fin1.eof())
	{
		hasVal1 = 0;
	}
	else { val1 = stoi(str1); }
	if (str2 == "," || fin2.eof())
	{
		hasVal2 = 0;
	}
	else { val2 = stoi(str2); }

	while (hasVal1 && hasVal2) {
		if (val1 <= val2) {
			fout << val1 << " ";
			fin1 >> str1;
			if (str1 == ",")
			{
				hasVal1 = 0;
			}
			else
			{
				val1 = stoi(str1);
			}
		}
		else {
			fout << val2 << " ";
			fin2 >> str2;
			if (str2 == ",")
			{
				hasVal2 = 0;
			}
			else
			{
				val2 = stoi(str2);
			}
		}
	}
	while (hasVal1) {
		fout << val1 << " ";
		fin1 >> str1;
		if (str1 == ",")
		{
			hasVal1 = 0;
		}
		else
		{
			val1 = stoi(str1);
		}
	}

	while (hasVal2) {
		fout << val2 << " ";
		fin2 >> str2;
		if (str2 == ",")
		{
			hasVal2 = 0;
		}
		else
		{
			val2 = stoi(str2);
		}
	}
	
}


void strange_sort(const string a)
{
	ifstream fin(a+".txt");
	int n = 1;
	int pp;
	fin>>pp;
	int p;
	for (; !fin.eof();)
	{
		p = fib(n);
		int i = 0;
		string F1 = a + "_" + to_string(n);
		ofstream fout(F1 + ".txt");
		bool fl = 1;
		for (; i < p && !fin.eof();)
		{
			int pp2;
			fin >> pp2;
			if (pp2 < pp)
			{
				fout <<pp << " , ";
				
				i++;
			}
			else
			{
				fout << pp;
				if(fin.eof())
				{
					fout << " , ";
				}
				else
				{
					fout << " ";
				}
			}
			pp = pp2;
		}
		
		print_zpt(fout, p-i-1);
		fout.close();
		n++;
	}
	fin.close();
	n--;
	int t1 = fib(n);
	string F1, F2 = a + "_" + to_string(2);
	for (int i = n; i > 2; i--)
	{
		F1 = a + "_" + to_string(i);
		ifstream fin1(F1 + ".txt");
		F2 = a+"_" + to_string(i-1);
		ifstream fin2(F2 + ".txt");
		ofstream fout("aaa.txt");
		
		for (int j = 0; j < t1; j++)
		{
			recovery(fin1, fin2, fout);
			if (i != 3)
			{
				fout << ", ";
			}
		}
		fout.close();
		fin1.close();
		fin2.close();
		remove((F2 + ".txt").c_str());
		remove((F1 + ".txt").c_str());

		rename("aaa.txt", (F2 + ".txt").c_str());
	}
	
	if (t1 > 2)
	{
		strange_sort(F2);
	}
	F1 = a + "_1";
	ifstream fin1(F1 + ".txt");
	ifstream fin2(F2 + ".txt");
	ofstream fout("aaa.txt");
	for (int j = 0; j < 2; j++)
	{
		recovery(fin1, fin2, fout);
		fout << ", ";
	}
	fout.close();
	fin1.close();
	fin2.close();
	remove((F2 + ".txt").c_str());
	remove((F1 + ".txt").c_str());
	remove((a + ".txt").c_str());


	rename("aaa.txt", (a + ".txt").c_str());
	
}

void strange_sort_main(string a)
{
	strange_sort(a);

	ifstream input(a + ".txt");
	ofstream run1(FF1);
	ofstream run2(FF2);
	int t;
	string str;
	input >> str;
	while (str != ",")
	{
		t = stoi(str);
		run1 << t << " ";
		input >> str;
	}
	input >> str;
	while (str != ",")
	{
		t = stoi(str);
		run2 << t << " ";
		input >> str;
	}
	input.close();
	run1.close();
	run2.close();
	ifstream F11(FF1), F22(FF2);
	ofstream fout(a + ".txt");

	int val1, val2;
	bool hasVal1 = (bool)(F11 >> val1);
	bool hasVal2 = (bool)(F22 >> val2);
	while (hasVal1 && hasVal2) {
		if (val1 <= val2) {
			fout << val1 << " ";
			hasVal1 = (bool)(F11 >> val1);
		}
		else {
			fout << val2 << " ";
			hasVal2 = (bool)(F22 >> val2);
		}
	}
	while (hasVal1) {
		fout << val1 << " ";
		hasVal1 = (bool)(F11 >> val1);
	}

	while (hasVal2) {
		fout << val2 << " ";
		hasVal2 = (bool)(F22 >> val2);
	}
	fout.close();
	F11.close();
	F22.close();
}

int main()
{
	/*char a[] = "inp1.txt";
	char* b = (char*)a;
	ofstream fout(a);
	int n =16;
	for (int i = 0; i < n; i++)
	{
		int t = (-1) * (rand() % 100 - 50);
		fout << t << " ";
		cout << t << " ";
	}
	fout.close();*/
	//marge_mod("inp1.txt");
	//marge_bal("inp1",n);
	strange_sort_main("inp");
}

/*Внешняя сортировка это упорядочивание наборов данных которые не в ОП,
а на жёстких дтсках.
Серия -  часть набора данных которая уже отсортированна.

Как работаетд:
1. Распределение на серии
2. слияние серий в отсортированный набор данных

Слияние:
1. Серии сливаются попарно 
2. Получается новая отсортированная серия

Методы слияния:
1. Естественного слияния
Исходные серии уже упорядочены

2. Метод сбалансированного слияния
2.1. разбивается на две равные части
2.2. Отсортированные части соединяются в один 
2.3. Каждая часть рекурсивно сортируется

3. Многофазеая сортировка
3.1. Изначально разбивается по несколким файлам
для удобства используют числа фибоначи*/