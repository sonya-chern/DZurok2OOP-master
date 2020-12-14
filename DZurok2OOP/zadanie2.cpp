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
			cout << "Контакт: ";
			for (int i = 0; i < sizeName; i++)	{	cout << Name[i];	}
				cout << endl;
		}
		else { cout << "Нет имени" << endl; }
		cout << "Мобильный телефон: " << mobPh << endl;
		cout << "Рабочий телефон: " << officePh << endl;
		cout << "Домашний телефон: " << homePh << endl;
		if (otherInfo) {
			cout << "Дополнительная информация о контакте: ";
			for (int i = 0; i < sizeOtherInfo; i++) { cout << otherInfo[i]; }
			cout << endl;
		}
		else { cout << "Нет информации" << endl; }
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
	cout << "Приветствую! Выберете действие: " << endl;
	do {
		cout << "1 - добавить контакт" << endl << "2 - удалить контакт" << endl << "3 - искать контакт по ФИО" << endl;
		cout << "4 - показать всех абонентов" << endl << "0 - закрыть приложение" << endl;
		cin >> Indik; cin.ignore(32767, '\n');
		system ("cls");
		switch (Indik) {
		case 1: {
			do {
				cout << "Нажмите 1, чтобы добавить контакт" << endl << "Нажмите 0 для возврата в предыдущее меню" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					char n[255]{ 0 }; 	char O[255]{ 0 };
					cout << "Введите имя, фамилию и отчество контакта: "; 	
					cin.get(n, 255);
					cout << "Мобильный телефон: "; 		cin >> m; cin.ignore(32767, '\n');
					cout << "Рабочий телефон: ";		cin >> of; cin.ignore(32767, '\n');
					cout << "Домашний телефон: ";		cin >> h; cin.ignore(32767, '\n');
					cout << "Дополнительную информацию об абоненте: ";		
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
			cout << "Какой контакт удалить? Выберете номер" << endl << "Нажмите 0 для возврата в предыдущее меню" << endl;
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
					/*PhoneBook.erase(PhoneBook.begin()+A);*/ //не работает
				}
				cout << endl << "Контакт удален" << endl;
			}
			else cout << "Неправильно выбран номер" << endl;
		}
		Sleep(5000);	system("cls");
		break;
		case 3: {
			do 	{ cout << "Нажмите 1 для поиска контакта по ФИО" << endl << "Нажмите 0 для возврата в предыдущее меню" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					cout << "Введите имя, фамилию и отчество контакта: "; 	gets_s(n);
					int indikSerch{ 0 };
					for (int i = 0; i < PhoneBook.size(); i++) {
						int serch = PhoneBook[i].SerchByName(n);
						if (serch) continue;
						else {
							PhoneBook[i].Print(); indikSerch++;
						}
					}
					if (!indikSerch) { cout << "Контакт не найден" << endl; }
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
				cout << "Нажмите 0 для возврата в предыдущее меню" << endl;
				cin >> A; 	cin.ignore(32767, '\n');
			} while (A != 0);
		}
		system("cls");
		break;
		default: cout << "Всего доброго!";
			break;
		}
	} while (Indik>0 && Indik<5);
}