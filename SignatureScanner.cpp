#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int readsignatures(string file, string file2);
int checksign(string file, string sm, string vsign, string name);
int complementation(int e, string s);
int r;

string fsign;
string rasp;

int main()
{
	string c;
	setlocale(LC_ALL, "Russian");
	if (!setlocale)
		complementation(1, "LOCALE specification error!");

	cout << "------------------------------------------����������� ������--------------------------------------------------\n\n\n";
	cout << "\n\n������� ������������ �����, ������� ���������� ���������: ";
	cin >> c;

	cout << "\n\n������� ������������ ����� � ����� ������ ��������: ";
	cin >> rasp;
	cout << "\n\n";

	readsignatures(rasp, c);
	if (!readsignatures)
		complementation(2, "������ � ����������� ������� ���������!");

	try
	{
		if (cout.fail() || cin.fail()) throw 9;
		if (!complementation) throw 10;
	}
	catch (int ex)
	{
		if (ex == 9)
			cout << "���� � ������ ����������� ������� �����/������!";
		else
			cout << "��������� ����������� ������! ������������� ��������� � ���������� ��� ���.";
		cin >> r;
		if (cin.fail()) exit(9);
		exit(ex);
	}

	cin >> r;
	return 0;
}

int readsignatures(string file, string file2)
{
	string sm;
	string vsign;
	string name;
	ifstream fs(file);

	if (!fs)
		complementation(2, "������! ���� �������� �� �������!");

	if (file == "" || file2 == "")
		complementation(1, "������ � ��������� ������������ �����");

	fs.seekg(0, 0);
	if (!fs.seekg(0,0))
		complementation(5, "��������� ������! ��������� ����������� ������������ ����� � ��������� �������.");

	char buff[50];
	fs >> buff;
	if (buff[0] == NULL)
		complementation(4, "������! ������ � ��������� �� �������!");

	int g;
	for (int i = 0; i < sizeof(buff); i++) if (buff[i] == '|') g = i;

	while (r < g)
	{
		sm += buff[r];
		r++;
	}

	r += 1;
	for (int i = r; i < sizeof(buff); i++) if (buff[i] == '*') g = i;

	while (r < g)
	{
		vsign += buff[r];
		r++;
	}
	r += 1;

	while (buff[r])
	{
		name += buff[r];
		r++;
	}

	if ((sm == "") || (vsign == "") || (name == ""))
		complementation(3, "������ � ������ ���������!");

	fs.close();
	if (fs.is_open())
		complementation(7, "������ � ������ � ������!");

	checksign(file2, sm, vsign, name);
	if (!checksign)
		complementation(6, "������ � �������� ��������� �����!");

	try
	{
		if (cout.fail() || cin.fail()) throw 9;
		if (!complementation) throw 10;
	}
	catch (int ex)
	{
		if (ex == 9)
			cout << "���� � ������ ����������� ������� �����/������!";
		else
			cout << "��������� ����������� ������! ������������� ��������� � ���������� ��� ���.";
		cin >> r;
		if (cin.fail()) exit(9);
		exit(ex);
	}

	return 0;
}

int checksign(string file, string sm, string vsign, string name)
{
	
	if (file == "" || sm == "" || vsign == "" || name == "")
		complementation(1, "������ � ��������� ���������!");

	char line[50];
	char mz[3]; mz[2] = 0;
	ifstream ff;

	ff.open(file, ios::binary | ios::in | ios::beg);
	if (ff.fail())
		complementation(2, "������! �������� ���� � �����!");

	ff.read((char*)&mz, 2);
	if (ff.fail())
		complementation(5, "������! ��������� ����������� ���������� �����!");
	if (strcmp(mz, "MZ") != 0)
		complementation(3, "������! ������ �� exe ����!");

	ff.seekg(0, ios::end);
	if (!ff.tellg())
		complementation(6, "������ � ������ � ����� �����!");

	int filesize = ff.tellg();
	if ((filesize - 2) < vsign.length())
		complementation(4, "������ ������� ��������� ����!");

	ff.seekg(stoi(sm), 0);
	if (!ff.tellg())
		complementation(6, "������ � ������ � ����� �����!");

	ff.read((char*)&line, vsign.length());
	if (ff.fail())
		complementation(7, "������ � ������� ���� ������������ �����!");

	for (int i = 0; i < vsign.length(); i++) fsign += line[i];
	if (fsign == vsign) cout << "��������! � ��������� ����� �� ������������ " << file << " ���������� ��������� ������ ������� " << name << "!" << "\n\n\n" << endl;
	else cout << "� ��������� ����� �� ������������ " << file << " �������� ����������� ������ �� �������.\n\n\n" << endl;

	try
	{
		if (!vsign.length()) throw 8;
		if (cout.fail() || cin.fail()) throw 9;
		if (!complementation) throw 10;
	}
	catch (int ex)
	{
		if (ex == 8)
			cout << "������ � ������ � ������� � ���������!";
		if (ex == 9)
			cout << "���� � ������ ����������� ������� �����/������!";
		else
			cout << "��������� ����������� ������! ������������� ��������� � ���������� ��� ���.";
		cin >> r;
		if (cin.fail()) exit(9);
		exit(ex);
	}
	return 0;
}

int complementation(int e, string s)
{
	cout << s << "\n\n\n";
	cin >> s;
	if (cout.fail() || cin.fail()) exit(9);
	exit(e);
}