#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;

const double PI = 3.1415926;

string rand_str(int size)
{
	string ans = "";
	for (int i = 0; i < size; i++)
	{
		ans = ans + char(rand() % 2 + 48);
	}
	return(ans);
}

char summ(char a, char b)
{
	if (a == '0' and b == '0')
		return '0';
	if ((a == '0' and b == '1') or (a == '1' and b == '0'))
		return '1';
	return '0';
}


string CA(int prn)
{

	string start="1111111111", gr1 = start, gr2 = start, answ;
	int prn_num[2], n=start.length();
	char c;
	int i = 0;
	switch (prn)
	{
	case 1: prn_num[0] = 2; prn_num[1] = 6; break;
	case 2: prn_num[0] = 3; prn_num[1] = 7; break;
	case 3: prn_num[0] = 4; prn_num[1] = 8; break;
	case 4: prn_num[0] = 5; prn_num[1] = 9; break;
	case 5: prn_num[0] = 1; prn_num[1] = 9; break;
	case 6: prn_num[0] = 2; prn_num[1] = 10; break;
	case 7: prn_num[0] = 1; prn_num[1] = 8; break;
	case 8: prn_num[0] = 2; prn_num[1] = 9; break;
	case 9: prn_num[0] = 3; prn_num[1] = 10; break;
	case 10: prn_num[0] = 2; prn_num[1] = 3; break;
	case 11: prn_num[0] = 3; prn_num[1] = 4; break;
	case 12: prn_num[0] = 5; prn_num[1] = 6; break;
	case 13: prn_num[0] = 6; prn_num[1] = 7; break;
	case 14: prn_num[0] = 7; prn_num[1] = 8; break;
	case 15: prn_num[0] = 8; prn_num[1] = 9; break;
	case 16: prn_num[0] = 9; prn_num[1] = 10; break;
	case 17: prn_num[0] = 1; prn_num[1] = 4; break;
	case 18: prn_num[0] = 2; prn_num[1] = 5; break;
	case 19: prn_num[0] = 3; prn_num[1] = 6; break;
	case 20: prn_num[0] = 4; prn_num[1] = 7; break;
	case 21: prn_num[0] = 5; prn_num[1] = 8; break;
	case 22: prn_num[0] = 6; prn_num[1] = 9; break;
	case 23: prn_num[0] = 1; prn_num[1] = 3; break;
	case 24: prn_num[0] = 4; prn_num[1] = 6; break;
	case 25: prn_num[0] = 5; prn_num[1] = 7; break;
	case 26: prn_num[0] = 6; prn_num[1] = 8; break;
	case 27: prn_num[0] = 7; prn_num[1] = 9; break;
	case 28: prn_num[0] = 8; prn_num[1] = 10; break;
	case 29: prn_num[0] = 1; prn_num[1] = 6; break;
	case 30: prn_num[0] = 2; prn_num[1] = 7; break;
	case 31: prn_num[0] = 3; prn_num[1] = 8; break;
	case 32: prn_num[0] = 4; prn_num[1] = 9; break;
	}

	do
	{
		c = summ(gr1[2], gr1[9]);
		for (i = n-1; i > 0; i--)
			gr1[i] = gr1[i - 1];
		gr1[0] = c;
		c = summ(gr2[9],summ(gr2[1], summ(gr2[2], summ(gr2[5], summ(gr2[7], gr2[8])))));
		for (i = n-1; i > 0; i--)
			gr2[i] = gr2[i - 1];
		gr2[0] = c;
		//cout << gr1 << endl << gr2<<endl<< (gr1 == start) <<endl<< (gr2 == start)<<endl;
		answ = summ(gr1[n - 1], summ(gr2[prn_num[0]], gr2[prn_num[1]]))+ answ;
	} while (gr1 != start or gr2 != start);

	return answ;
}
int main()
{
	srand(time(NULL));
	string h = CA(1);
	string s,s1, rand,stroka,my_str="", sput_str="";
	int n, i,j, num, file_sizec=12, otstup=40,a=1,b=1, res, sdvig=0;
	//double res;

//сделать свой сигнал и сигнал со спутника
	ofstream my_file, sput_file;
	my_file.open("my_file.txt");
	sput_file.open("sput_file.txt");
	my_file << file_sizec << endl;
	sput_file << file_sizec << endl;
	for (i = 0; i < file_sizec; i++)
	{
		rand = rand_str(128);
		stroka = h + rand;
		my_file << stroka << endl;
		if (otstup > 0)
		{
			if (otstup < 1151)
			{
				stroka.erase(0, otstup);
				otstup = 0;
			}
			else
			{
				stroka = "";
				otstup = otstup - 1151;
			}
		}

		sput_file <<stroka<<endl;

	}
	my_file.close();



//получить сигнал со спутника
	ifstream file, orig_file;
	file.open("sput_file.txt");
	orig_file.open("my_file.txt");
	orig_file >> n;
	file >> n;

//прочитать сигнал со спутника
	while (orig_file >> s)
		my_str =my_str + s;
	while (file >> s)
		sput_str = sput_str + s;
//посчитать сдвиг
	if (sput_str.length() > 1023)
	{
		for (i = 0; i <= my_str.length() - 1023; i++)
		{
			res = 0;
			for (j = i; j < i + 1023; j++)
			{
				if (my_str[j] == '1')
					a = 1;
				if (my_str[j] == '0')
					a = -1;
				if (sput_str[j - i] == '1')
					b = 1;
				if (sput_str[j - i] == '0')
					b = -1;
				res = res + a * b;
				//cout <<my_str[j]<<" "<<sput_str[j-i]<<" "<< a*b<<" "<<res << endl;
			}
			if (res == 1023)
				sdvig = i;
		}
	}
	cout <<"sdvig: "<< sdvig << endl;

//Вычислить prn
	int schet[33], maxx = 0, numm=0;
	for (i = 0; i <= 32; i++)
		schet[i] = 0;
	for (j = 1; j <= 32; j++)
	{
		h = CA(j);
		for (i = 0; i < sput_str.length()-1023; i++)
		{
			s = sput_str.substr(i, i + 1023);
			if (s == h)
				schet[j] = schet[j] + 1;
		}
	}
	for(i=1;i<=32;i++)
		if (maxx < schet[i])
		{
			maxx = schet[i];
			numm = i;
		}
	cout << "PRN: " << numm << endl;

//вычисление координат спутника по центру, угловой скорости и времени
	double rx = 12, ry = 12, r = 25, rv = 32, t = 12, x = 0, y = 0;
	double grad = rv * t;
	bool dl;
	while (grad > 2 * PI)
		grad = grad - 2 * PI;
	double dop_x = r * cos(grad), dop_y = r * sin(grad);
	x = rx + dop_x;
	y = ry + dop_y;
	cout << x << endl << y << endl;
//Триангуляция
	n = 3;
	int* xs = new int[n];
	int* ys = new int[n];
	int* rs = new int[n];
	for (i = 0; i < n; i++)
	{
		xs[i] = i;
		ys[i] = i;
		rs[i] = i;
	}
	for (i = xs[0] - r; i <= xs[0] + r; i++)
	{
		for (j = xs[0] - r; j <= xs[0] + r; j++)
		{
			if ((i - xs[0]) * (i - xs[0]) + (j - xs[0]) * (j - xs[0]) > r * r - 2 && (i - xs[0]) * (i - xs[0]) + (j - xs[0]) * (j - xs[0]) < r * r + 2)
			{
				dl = true;
				for (int k = 1; k < n; k++)
				{
					if (!((i - xs[k]) * (i - xs[k]) + (j - xs[k]) * (j - xs[k]) > r * r - 2 && (i - xs[k]) * (i - xs[k]) + (j - xs[k]) * (j - xs[k]) < r * r + 2))
						dl = false;
				}
				if (dl == true)
					cout << "coordinates: " << i << " " << j << endl;
			}
		}
	}
	delete[] rs;
	delete[] ys;
	delete[] xs;
	return 0;
}
