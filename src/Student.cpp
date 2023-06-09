#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::setw;
using std::streamsize;
using std::string;

#include "Student.h"

//--------------------------------------------------------
//----------(group)---------------------------------------

group::group() : name_faculti("не вказано"), group_n("не вказано")
{
}
group::group(string faculti, string group) : name_faculti(faculti), group_n(group)
{
}

//--------------------------------------------------------
//----------(Student)-------------------------------------

Student::Student()
	: budget_edu(2), name_student("не вказано"), name_kurator("не вказано"), enroll_year(0), faculti_and_group(), name_building_cafedra(NO_INDICA)
{
	cout << endl << "Був викликаний конструктор за замовчуванням" << endl;
}

Student::Student(unsigned int budget_edu, string name_student, string name_kurator, unsigned int enroll_year, string name_faculti, string group_n,
		 enum cafedra name_building_cafedra)
	: budget_edu(budget_edu), name_student(name_student), name_kurator(name_kurator), enroll_year(enroll_year),
	  faculti_and_group(name_faculti, group_n), name_building_cafedra(name_building_cafedra)
{
	cout << endl << "Був викликаний конструктор з параметрами" << endl;
}

Student::Student(const Student &student)
	: budget_edu(student.budget_edu), name_student(student.name_student), name_kurator(student.name_kurator), enroll_year(student.enroll_year),
	  faculti_and_group(student.faculti_and_group.name_faculti, student.faculti_and_group.group_n),
	  name_building_cafedra(student.name_building_cafedra)
{
	cout << endl << "Був виклакений конструктор копіювання" << endl;
}

Student::~Student()
{
	cout << endl << "Був виклакений деструктор Student" << endl;
}

//--------------------------------------------------------
//----------(budget_edu)----------------------------------

string Student::get_budget_edu() const
{
	if (budget_edu == 1)
		return "так";
	else if (budget_edu == 0)
		return "ні";
	else
		return "не вказано";
};

void Student::set_budget_edu(const string &state_budget_edu)
{
	if (state_budget_edu == "так")
		this->budget_edu = 1;
	else if (state_budget_edu == "ні")
		this->budget_edu = 0;
	else
		this->budget_edu = 2;
};

//--------------------------------------------------------
//----------(name_student)--------------------------------

string Student::get_name_student() const
{
	return name_student;
};

void Student::set_name_student(const string &state_name_student)
{
	name_student = state_name_student.substr(0, 66);
};

//--------------------------------------------------------
//----------(name_kurator)---------------------------------

string Student::get_name_kurator() const
{
	return name_kurator;
};
void Student::set_name_kurator(const string &state_name_kurator)
{
	name_kurator = state_name_kurator.substr(0, 66);
};

//--------------------------------------------------------
//----------(enroll_year)---------------------------------

unsigned int Student::get_enroll_year() const
{
	return enroll_year;
};

void Student::set_enroll_year(const unsigned int &state_enroll_year)
{
	if (state_enroll_year < 2017 || state_enroll_year > 2022)
		this->enroll_year = 0;
	else
		this->enroll_year = state_enroll_year;
};

//--------------------------------------------------------
//----------(name_faculti)-------------------------------------

string Student::get_name_faculti() const
{
	return faculti_and_group.name_faculti;
};
void Student::set_name_faculti(const string &state_name_faculti)
{
	faculti_and_group.name_faculti = state_name_faculti.substr(0, 8);
};

//--------------------------------------------------------
//----------(group_n)-------------------------------------

string Student::get_group_n() const
{
	return faculti_and_group.group_n;
};
void Student::set_group_n(const string &state_group_n)
{
	faculti_and_group.group_n = state_group_n.substr(0, 10);
};

//--------------------------------------------------------
//----------(name_building_cafedra)-----------------------

string Student::get_name_building_cafedra() const
{
	if (name_building_cafedra == BK)
		return "ВК";
	else if (name_building_cafedra == GAK)
		return "ГАК";
	else if (name_building_cafedra == Y1)
		return "У1";
	else if (name_building_cafedra == Y2)
		return "У2";
	else
		return "не вказано";
};
void Student::set_name_building_cafedra(const string &state_building_cafedra)
{
	if (state_building_cafedra == "ВК")
		this->name_building_cafedra = BK;
	else if (state_building_cafedra == "ГАК")
		this->name_building_cafedra = GAK;
	else if (state_building_cafedra == "У1")
		this->name_building_cafedra = Y1;
	else if (state_building_cafedra == "У2")
		this->name_building_cafedra = Y2;
	else
		this->name_building_cafedra = NO_INDICA;
};

//--------------------------------------------------------
//----------(write_on_screen)----------------------------

void Student::write_on_screen() const
{
	cout << endl
	     << "Форма навчання: " << get_budget_edu() << endl
	     << "Ім'я студента: " << get_name_student() << endl
	     << "Ім'я куратора: " << get_name_kurator() << endl
	     << "Рік вступу: " << get_enroll_year() << endl
	     << "Факультет: " << get_name_faculti() << endl
	     << "Група: " << get_group_n() << endl
	     << "Корпус кафедри: " << get_name_building_cafedra() << endl;
};

//--------------------------------------------------------
//----------(read_from_screen)----------------------------

void Student::read_from_screen(string &str, unsigned int n_symbol)
{
	cin >> setw((int)n_symbol) >> str;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

void Student::read_from_screen(unsigned int &number)
{
	cin >> number;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

//--------------------------------------------------------
//----------(write_info_student)--------------------------

Student *Student::write_info_student()
{
	string info_budget_edu;
	cout << "Навчання на бюджеті:";
	read_from_screen(info_budget_edu, 6);
	set_budget_edu(info_budget_edu);

	string info_name_student;
	cout << "Ім'я студента: ";
	read_from_screen(info_name_student, 66);
	set_name_student(info_name_student);

	string info_name_kurator;
	cout << "Ім'я куратора: ";
	read_from_screen(info_name_kurator, 66);
	set_name_kurator(info_name_kurator);

	unsigned int info_enroll_year = 0;
	cout << "Рік вступу: ";
	read_from_screen(info_enroll_year);
	set_enroll_year(info_enroll_year);

	string info_name_faculti;
	cout << "Факультет: ";
	read_from_screen(info_name_faculti, 20);
	set_name_faculti(info_name_faculti);

	string info_group_n;
	cout << "Група: ";
	read_from_screen(info_group_n, 20);
	set_group_n(info_group_n);

	string info_name_building_cafedra;
	cout << "Корпус кафедри: ";
	read_from_screen(info_name_building_cafedra, 6);
	set_name_building_cafedra(info_name_building_cafedra);

	return NULL;
};
