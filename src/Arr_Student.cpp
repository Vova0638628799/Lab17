#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "Student.h"
#include "Arr_Student.h"

Arr_Student::Arr_Student(){};

Arr_Student::~Arr_Student()
{	
	for(unsigned int i = 0; i < arr_students.size(); i++){
		delete arr_students[i];
	}
	arr_students.clear();
	cout << endl << "Був виклакений деструктор класса Arr_Student" << endl;
};

unsigned int Arr_Student::get_n_student() const
{
	return (unsigned int)arr_students.size();
};
void Arr_Student::add_student(Student &student)
{
	arr_students.emplace_back(&student);
};

void Arr_Student::remove_student(const unsigned int index)
{
	if (arr_students.size() < index || index <= 0)
		return;
	
	delete arr_students[index - 1];
	arr_students.erase(arr_students.cbegin() + index - 1);
};

Student Arr_Student::get_student(unsigned int index) const
{
	if (arr_students.size() < index || index <= 0) {
		Student student;
		return student;
	}
	
	return arr_students[index - 1][0];
};

void Arr_Student::print() const
{
	if (arr_students.size() == 0) {
		cout << endl << "Кількість студентів 0" << endl;
		return;
	}

	for (unsigned int i = 0, j = 1; i < arr_students.size(); i++, j++) {
		cout << endl << "Студент номер: " << j << endl;
		arr_students[i]->write_on_screen();
	}
};

vector<Student> Arr_Student::find_student(unsigned int year) const
{
	int n_found_students = 0;
	vector<Student> arr_found_students;
	
	if (year < 2017 || year > 2022)
		return arr_found_students;

	for (unsigned int i = 0, j = 0; i < arr_students.size(); i++)
		if (arr_students[i]->get_enroll_year() == year) 
			arr_found_students.push_back(arr_students[i][0]);
		
	return arr_found_students;
};










