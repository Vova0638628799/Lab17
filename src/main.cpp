#include <iostream>
#include <string>
#include <limits>
#include <vector>

#define ADD_ELEMENT 1
#define REMOVE_ELEMENT 2
#define PRINT_ONE_ELEMETN 3
#define PRINT_ALL_ELEMETN 4
#define FINDE_ELEMETN 5
#define EXIT 6

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;

#include "Student.h"
#include "Arr_Student.h"

int main()
{
	int finish_program = 1;
	Arr_Student arr_student;

	{
		cout << endl << "Демонстрація роботи конструкторів класу Student" << endl;
		Student student1(1, "коля", "ваня", 2018, "БК", "23", Y1);
		student1.write_on_screen();
		Student student2(student1);
		student2.write_on_screen();
	}
	
	do {
		int operation_n = 0;

		cout << endl
		     << "Програма для роботи зі списком" << endl
		     << "1. Додати студента до списку" << endl
		     << "2. Видалити студента зі списку" << endl
		     << "3. Вивести окремого студента" << endl
		     << "4. Вивести весь список на екран" << endl
		     << "5. Вивести студентів певного року вступу" << endl
		     << "6. Вихід" << endl
		     << "Оберіть номер операції: ";
		cin >> operation_n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (operation_n == ADD_ELEMENT) {
		
			Student *student = new Student;
			student->write_info_student();

			arr_student.add_student(*student);
			arr_student.print();
			
		} else if (operation_n == REMOVE_ELEMENT) {
		
			unsigned int index = 0;

			cout << endl << "Введіть номер студента: ";
			cin >> index;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			arr_student.remove_student(index);
			arr_student.print();
			
		} else if (operation_n == PRINT_ONE_ELEMETN) {
		
			unsigned int index = 0;
				
			cout << endl << "Введіть номер студента: ";
			cin >> index;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			Student student = arr_student.get_student(index);
			
			student.write_on_screen();
			
		} else if (operation_n == PRINT_ALL_ELEMETN) {
		
			arr_student.print();
			
		} else if (operation_n == FINDE_ELEMETN) {
	
			unsigned int year = 0;

			cout << endl << "Введіть рік вступники якого вас цікавлять: ";
			cin >> year;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			vector<Student> arr_found_students =  arr_student.find_student(year);
			
			for (unsigned int i = 0, j = 0; i < arr_found_students.size(); i++) 
			arr_found_students[i].write_on_screen();

		} else if (operation_n == EXIT) {
		
			finish_program = 0;
			
		} else
			cout << endl << "Ви ввели некоректні дані" << endl;

	} while (finish_program != 0);

	return 0;
}
