#ifndef Arr_Student_H
#define Arr_Student_H

class Arr_Student {
	vector<Student *> arr_students;

    public:
	Arr_Student();
	~Arr_Student();
	unsigned int get_n_student() const;
	void add_student(Student &student);
	void remove_student(const unsigned int index);
	Student get_student(unsigned int index) const;
	void print() const;
	vector<Student> find_student(unsigned int year) const;
};

#endif
