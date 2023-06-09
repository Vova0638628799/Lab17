#include <iostream>

using std::string;

#include "Student.h"
#include <gtest/gtest.h>

TEST(ClassStudent, test_default_construcotr)
{
	Student student_actual;
	string expected_str_value = "не вказано";
	unsigned int expected_num_value = 0;

	ASSERT_EQ(expected_str_value, student_actual.get_budget_edu());
	ASSERT_EQ(expected_str_value, student_actual.get_name_student());
	ASSERT_EQ(expected_str_value, student_actual.get_name_kurator());
	ASSERT_EQ(expected_str_value, student_actual.get_name_faculti());
	ASSERT_EQ(expected_str_value, student_actual.get_group_n());
	ASSERT_EQ(expected_str_value, student_actual.get_name_building_cafedra());
	ASSERT_EQ(expected_num_value, student_actual.get_enroll_year());
}

TEST(ClassStudent, test_construcotr_with_param)
{
	Student student_actual(0, "не вказано", "не вказано", 0, "не вказано", "не вказано", NO_INDICA);
	string expected_str_value[] = { "не вказано", "ні" };
	unsigned int expected_num_value = 0;

	ASSERT_EQ(expected_str_value[1], student_actual.get_budget_edu());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_student());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_kurator());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_faculti());
	ASSERT_EQ(expected_str_value[0], student_actual.get_group_n());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_building_cafedra());
	ASSERT_EQ(expected_num_value, student_actual.get_enroll_year());
}

TEST(ClassStudent, test_construcotr_cpy)
{
	Student student_expect(1, "не вказано", "не вказано", 0, "не вказано", "не вказано", NO_INDICA);
	Student student_actual(student_expect);

	ASSERT_EQ(student_expect.get_budget_edu(), student_actual.get_budget_edu());
	ASSERT_EQ(student_expect.get_name_student(), student_actual.get_name_student());
	ASSERT_EQ(student_expect.get_name_kurator(), student_actual.get_name_kurator());
	ASSERT_EQ(student_expect.get_name_faculti(), student_actual.get_name_faculti());
	ASSERT_EQ(student_expect.get_group_n(), student_actual.get_group_n());
	ASSERT_EQ(student_expect.get_name_building_cafedra(), student_actual.get_name_building_cafedra());
	ASSERT_EQ(student_expect.get_enroll_year(), student_actual.get_enroll_year());
}

TEST(ClassStudent, test_setter_and_getter)
{
	string expected_str_value[] = { "не вказано", "ні", "У2" };
	unsigned int expected_num_value = 2018;

	Student student_actual;
	student_actual.set_budget_edu(expected_str_value[1]);
	student_actual.set_name_student(expected_str_value[0]);
	student_actual.set_name_kurator(expected_str_value[0]);
	student_actual.set_name_faculti(expected_str_value[1]);
	student_actual.set_group_n(expected_str_value[1]);
	student_actual.set_name_building_cafedra(expected_str_value[2]);
	student_actual.set_enroll_year(expected_num_value);

	ASSERT_EQ(expected_str_value[1], student_actual.get_budget_edu());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_student());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_kurator());
	ASSERT_EQ(expected_str_value[1], student_actual.get_name_faculti());
	ASSERT_EQ(expected_str_value[1], student_actual.get_group_n());
	ASSERT_EQ(expected_str_value[2], student_actual.get_name_building_cafedra());
	ASSERT_EQ(expected_num_value, student_actual.get_enroll_year());
}
