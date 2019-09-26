#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <assert.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string Convertion(char input[])
{
	std::stringstream stream;
	int t[256];
	for (int i = 0; input[i] != '\0'; i++ )
	{
		t[i] = input[i];
		stream << std::hex << t[i];
	}
	string output(stream.str());
	return output;
}

char Ivestis_kr(char pasirinkimas)
{
	cin >> pasirinkimas;
	while (pasirinkimas != 'r')
	{
		if (pasirinkimas == 'f')
			break;
		cout << "Neteisingas kriterijus. Bandykite dar karta." << endl;
		cin >> pasirinkimas;
	}
	return pasirinkimas;
}

char Ivestis_sk(char pasirinkimas)
{
	cin >> pasirinkimas;
	while (pasirinkimas != 'y')
	{
		if (pasirinkimas == 'n')
			break;
		cout << "Neteisingas kriterijus. Bandykite dar karta." << endl;
		cin >> pasirinkimas;
	}
	return pasirinkimas;
}

void atsakymas(std::ofstream& out, string Hash_output, size_t output_sz)
{
	int k = 0;
	for (int i = 0; i < output_sz; i++)
	{
		if (k < Hash_output.length())
		{
			out << Hash_output[k];
			k++;
		}
		else
		{
			k = 0;
			out << Hash_output[k];
		}
	}
	out << endl;
}

void skaitymas(std::ofstream& out, char Hash_input[], size_t output_sz)
{
	Time test;
	std::ifstream in;
	in.open("duomenu_failas.txt");
	string temp;
	assert(!in.fail());
	in >> temp;
	for ( int i = 0; i < temp.length(); i++)
		Hash_input[i] = temp[i];
	test.Start_clock();
	temp = Convertion(Hash_input);
	test.Stop_clock();
	test.Sum_time();
	atsakymas(out, temp, output_sz);
	while (!in.eof())
	{
		in >> temp;
		for ( int i = 0; i < temp.length(); i++)
			Hash_input[i] = temp[i];
		test.Start_clock();
		temp = Convertion(Hash_input);
		test.Stop_clock();
		test.Sum_time();
		atsakymas(out, temp, output_sz);
	}
	test.get_all(out);
	in.close();
}

int main()
{
start:
	char Hash_input[1000], pasirinkimas;
	string Hash_output = "";
	size_t output_sz = 16;
	cout << "Ar failus ivesite ranka (r), ar is failo (f)? ";
	pasirinkimas = Ivestis_kr(pasirinkimas);
	std::ofstream out("tuscias.txt", std::ofstream::app);
	switch (pasirinkimas)
	{
	case 'r':
	{
		cout << "Iveskite teksta, kuri norite konvertuoti: ";
		cin >> Hash_input;
		Hash_output = Convertion(Hash_input);
		atsakymas(out, Hash_output, output_sz);
		cout << "Ar norite bandyti dar karta? (y/n) ";
		pasirinkimas = Ivestis_sk(pasirinkimas);
		if (pasirinkimas == 'y')
			goto start;
		out.close();
		break;
	}
	case 'f':
	{
		skaitymas(out, Hash_input, output_sz);
		cout << "Ar norite bandyti dar karta? (y/n) ";
		pasirinkimas = Ivestis_sk(pasirinkimas);
		if (pasirinkimas == 'y')
			goto start;
		out.close();
		break;
	}
	}
}