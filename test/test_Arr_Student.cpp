#include <iostream>
#include <vector>

using std::string;
using std::vector;

#include "Student.h"
#include "Arr_Student.h"

#include <gtest/gtest.h>

TEST(ClassArrStudent, test_add_student)
{
	Student *student1 = new Student;
	Student *student2 = new Student;
	Arr_Student arr_student;
	unsigned int expected_n_students = 0;

	arr_student.add_student(*student1);
	expected_n_students = 1;
	//Перевірка додавання елементу до порожнього масиву
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());

	arr_student.add_student(*student2);
	expected_n_students = 2;
	//Перевірка додавання елементу до масиву у якому вже є елементи
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());
}

TEST(ClassArrStudent, test_delete_student)
{
	Student *student1 = new Student;
	Student *student2 = new Student;
	Arr_Student arr_student;
	arr_student.add_student(*student1);
	arr_student.add_student(*student2);
	unsigned int expected_n_students = 1;

	arr_student.remove_student(1);
	//Перевіряємо стандартне видалення елементів
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());

	arr_student.remove_student(2);
	//Перевірка на видалення елемнта за індиксом який більше поточного максимального індекса
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());

	arr_student.remove_student(1);
	expected_n_students = 0;
	
	//Перевірка на видалення останнього елемента
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());

	arr_student.remove_student(1);
	expected_n_students = 0;
	
	//Перевірка на видалення з порожнього масиву
	ASSERT_EQ(expected_n_students, arr_student.get_n_student());
}

TEST(ClassArrStudent, test_get_student)
{
	Student *student1 = new Student(0, "Ваня", "не вказано", 0, "не вказано", "не вказано", BK);
	Student *student2 = new Student(0, "Петя", "не вказано", 0, "не вказано", "не вказано", GAK);
	Arr_Student arr_student;
	arr_student.add_student(*student1);
	arr_student.add_student(*student2);

	Student expect_student(0, "Ваня", "не вказано", 0, "не вказано", "не вказано", NO_INDICA);
	Student actual_student = arr_student.get_student(1);
	
	//Перевірка на отримання елементу з масиву
	ASSERT_EQ(expect_student.get_name_student(), actual_student.get_name_student());
	
	Student expected_student2;
	actual_student = arr_student.get_student(3);
	//Перевірка на отримання елементу індекс якого не входить у діапазон
	ASSERT_EQ(expected_student2.get_name_student(), actual_student.get_name_student());
}

TEST(ClassArrStudent, test_found_student)
{
	Student *student1 = new Student(0, "Ваня", "не вказано", 2018, "не вказано", "не вказано", Y1);
	
	Student *student2 = new Student(0, "Петя", "не вказано", 2018, "не вказано", "не вказано", Y2);
	
	Arr_Student arr_student;
	arr_student.add_student(*student1);
	arr_student.add_student(*student2);

	vector<Student> expected_arr_student = {*student1, *student2};
	
	vector<Student> actual_arr_student = arr_student.find_student(2018);
	
	//Перевірка пошуку студентів
	for(unsigned int i = 0; i < expected_arr_student.size();i++)
		ASSERT_EQ(expected_arr_student[i].get_name_student(), actual_arr_student[i].get_name_student());

	actual_arr_student = arr_student.find_student(2014);
	
	//Перевірка пошуку студентів яких не має у списку і не може бути у списку
	ASSERT_EQ(0, actual_arr_student.size());
}














