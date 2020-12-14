#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iterator>
#include<cctype>
#include "windows.h"
using namespace std;
uint64_t m{ 0 }, of{ 0 }, h{ 0 };
//const int sizeBook = 10;
int Indik, A;
class Abonent {
	int sizeName;
	int sizeOtherInfo;
	char* Name;
	uint64_t mobPh;
	uint64_t officePh;
	uint64_t homePh;
	char* otherInfo;
public:
	Abonent(const char* n, uint64_t m, uint64_t of, uint64_t h, const char* O) {
		sizeName = (int)strlen(n) + 1; 
		Name = new char[sizeName];	
		strcpy(Name, n);
		mobPh = m;
		officePh = of;
		homePh = h;
		sizeOtherInfo = (int)strlen(O) + 1;	
		otherInfo = new char[sizeOtherInfo]; 
		strcpy(otherInfo, O);
	}
	Abonent() : sizeName{ 0 }, sizeOtherInfo{ 0 }, Name{ nullptr }, mobPh{ 0 }, officePh{ 0 }, homePh{ 0 }, otherInfo{ nullptr }{}
		
	Abonent (const Abonent& otherAbonent) {  
		this->sizeName = otherAbonent.sizeName;
		this->Name = new char[sizeName];
		strcpy(Name, otherAbonent.Name);
		this->mobPh = otherAbonent.mobPh;
		this->officePh = otherAbonent.officePh;
		this->homePh = otherAbonent.homePh;
		this->sizeOtherInfo = otherAbonent.sizeOtherInfo;
		this->otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, otherAbonent.otherInfo);
	}
	Abonent & operator = (const Abonent& otherAbonent) {
		this->sizeName = otherAbonent.sizeName;
		this->Name = new char[sizeName];
		strcpy(Name, otherAbonent.Name);
		this->mobPh = otherAbonent.mobPh;
		this->officePh = otherAbonent.officePh;
		this->homePh = otherAbonent.homePh;
		this->sizeOtherInfo = otherAbonent.sizeOtherInfo;
		this->otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, otherAbonent.otherInfo);
		return *this;
	}
	void SetName (const char* n) {
		sizeName = (int)strlen(n) + 1;
		Name = new char[sizeName];
		strcpy(Name, n);
	}
	char* GetName() {	return Name;	}
	void SetMobPh(uint64_t m) {	mobPh = m; }
	uint64_t GetMobPh() { return mobPh;	}
	void SetOfficePh(uint64_t of) {	officePh = of;	}
	uint64_t GetOfficePh() { return officePh; }
	void SetHomePh(uint64_t h) { homePh = h; }
	uint64_t GetHomePh() {	return homePh;	}
	void SetOtherInf(const char* O) {
		sizeOtherInfo = (int)strlen(O) + 1;
		otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, O);
	}
	char* GetOtherInf() {	return otherInfo;	}
	int SerchByName(const char* otherName) {	return _stricmp(Name, otherName);	}
	void Print() {
		if (Name) {
			cout << "�������: ";
			for (int i = 0; i < sizeName; i++)	{	cout << Name[i];	}
				cout << endl;
		}
		else { cout << "��� �����" << endl; }
		cout << "��������� �������: " << mobPh << endl;
		cout << "������� �������: " << officePh << endl;
		cout << "�������� �������: " << homePh << endl;
		if (otherInfo) {
			cout << "�������������� ���������� � ��������: ";
			for (int i = 0; i < sizeOtherInfo; i++) { cout << otherInfo[i]; }
			cout << endl;
		}
		else { cout << "��� ����������" << endl; }
	}
		~Abonent() { 
			if (Name != nullptr) {
				delete[] Name; Name = nullptr;
			}
			if (otherInfo != nullptr) {
				delete[] otherInfo; otherInfo = nullptr;
			}
		}
};
vector<Abonent> PhoneBook;
void main() {
	setlocale(LC_ALL, "");
	int ind = 0;
	char n[255]{ 0 };
	char O[255]{ 0 };
	cout << "�����������! �������� ��������: " << endl;
	do {
		cout << "1 - �������� �������" << endl << "2 - ������� �������" << endl << "3 - ������ ������� �� ���" << endl;
		cout << "4 - �������� ���� ���������" << endl << "0 - ������� ����������" << endl;
		cin >> Indik; cin.ignore(32767, '\n');
		system ("cls");
		switch (Indik) {
		case 1: {
			do {
				cout << "������� 1, ����� �������� �������" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					char n[255]{ 0 }; 	char O[255]{ 0 };
					cout << "������� ���, ������� � �������� ��������: "; 	
					cin.get(n, 255);
					cout << "��������� �������: "; 		cin >> m; cin.ignore(32767, '\n');
					cout << "������� �������: ";		cin >> of; cin.ignore(32767, '\n');
					cout << "�������� �������: ";		cin >> h; cin.ignore(32767, '\n');
					cout << "�������������� ���������� �� ��������: ";		
					cin.get(O, 255);
					PhoneBook.insert(PhoneBook.end(), Abonent(n, m, of, h, O));
				}
			} while (A == 1);
		}
		break;
		case 2: { 
			for (int i = 0; i < PhoneBook.size(); i++) {
			cout << i + 1 << " "; 
			PhoneBook[i].Print(); cout << endl;
			}
			cout << "����� ������� �������? �������� �����" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
			cin >> A; cin.ignore(32767, '\n');
			if (A > 0 && A <= PhoneBook.size()) {
				if (PhoneBook.size() == 1) {
					PhoneBook.clear();
				}
				else {
					--A;
					vector<Abonent>Temp;
					for (int i = 0; i < PhoneBook.size(); i++) {
						if (i!=A) {
							Temp.push_back(PhoneBook[i]);
						}
					}
					PhoneBook.clear();
					PhoneBook = Temp;
					Temp.clear();
					/*PhoneBook.erase(PhoneBook.begin()+A);*/ //�� ��������
				}
				cout << endl << "������� ������" << endl;
			}
			else cout << "����������� ������ �����" << endl;
		}
		Sleep(5000);	system("cls");
		break;
		case 3: {
			do 	{ cout << "������� 1 ��� ������ �������� �� ���" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					cout << "������� ���, ������� � �������� ��������: "; 	gets_s(n);
					int indikSerch{ 0 };
					for (int i = 0; i < PhoneBook.size(); i++) {
						int serch = PhoneBook[i].SerchByName(n);
						if (serch) continue;
						else {
							PhoneBook[i].Print(); indikSerch++;
						}
					}
					if (!indikSerch) { cout << "������� �� ������" << endl; }
				}
			} while (A == 1);
		}
		break;
		case 4: {
			for (int i = 0; i < PhoneBook.size(); i++) {
				cout << i + 1 << " "; 
				PhoneBook[i].Print(); cout << endl;
			}
			do {
				cout << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; 	cin.ignore(32767, '\n');
			} while (A != 0);
		}
		system("cls");
		break;
		default: cout << "����� �������!";
			break;
		}
	} while (Indik>0 && Indik<5);
}