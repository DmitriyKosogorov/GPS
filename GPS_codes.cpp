#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<vector>
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
	string h = CA(1);
	string s,s1,fin="", ca="", rand,rand1,rand2,for_sput="0000", ost="0000",normal="";
	int n, i,j, num, file_sizec=12;
	bool b;

//сделать свой сигнал и сигнал со спутника
	ofstream my_file, sput_file;
	my_file.open("my_file.txt");
	sput_file.open("sput_file.txt");
	my_file << file_sizec << endl;
	sput_file << file_sizec << endl;
	for (i = 0; i < file_sizec; i++)
	{
		rand = rand_str(128);
		rand1 = rand;
		rand2 = rand.substr(rand1.length() - ost.length(), rand1.length());
		for_sput = ost + rand1.erase(rand1.length()-ost.length(),rand1.length());
		ost = rand2;
		sput_file << h << for_sput<<endl;
		my_file << h << rand<<endl;
	}
	my_file.close();



//получить сигнал со спутника
	ifstream file, orig_file;
	file.open("sput_file.txt");
	orig_file.open("my_file.txt");
	orig_file >> n;
	file >> n;

//прочитать сигнал со спутника
	for (i = 0; i < n; i++)
	{
		file >> s;
		orig_file >> s1;
		ca = s.substr(0,1023);
		s.erase(0,1022);
		s1.erase(0, 1022);
		fin = fin + s;
		normal = normal + s1;
	}

//посчитать сдвиг
	for (i = 0; i < fin.length(); i++)
	{
		b = true;
		for (j = i; j < fin.length(); j++)
		{
			if (fin[j] != normal[j - i])
				b = false;
		}
		if (b == true)
		{
			cout <<"Задержка = "<< i + 1 << endl;
		}
	}

//вычислсить prn по коду
	for (i = 0; i < 33; i++)
	{
		h = CA(i);
		if (h == ca)
			num = i;
	}

//вычисление координат спутника по центру, угловой скорости и времени
	double rx = 12, ry = 12, r = 25, rv = 32, t = 12, x = 0, y = 0;
	double grad = rv * t;
	while (grad > 2 * PI)
		grad = grad - 2 * PI;
	double dop_x = r * cos(grad), dop_y = r * sin(grad);
	x = rx + dop_x;
	y = ry + dop_y;

}