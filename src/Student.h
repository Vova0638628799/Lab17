#ifndef Student_H
#define Student_H

enum cafedra { BK, GAK, Y1, Y2, NO_INDICA };

struct group {
	string name_faculti;
	string group_n;

	group();
	group(string faculti, string group);
};

class Student {
	unsigned int budget_edu;
	string name_student;
	string name_kurator;
	unsigned int enroll_year;
	struct group faculti_and_group;
	enum cafedra name_building_cafedra;

    public:
	
	Student();
	Student(unsigned int budget_edu, string name_student, string name_kurator, unsigned int enroll_year, string name_faculti, string group_n,
		enum cafedra name_building_cafedra);
	Student(const Student &student);

	~Student();

	void write_on_screen() const;

	string get_budget_edu() const;
	void set_budget_edu(const string &state_budget_edu);

	string get_name_student() const;
	void set_name_student(const string &state_name_student);

	string get_name_kurator() const;
	void set_name_kurator(const string &state_name_kurator);

	unsigned int get_enroll_year() const;
	void set_enroll_year(const unsigned int &state_enroll_year);

	string get_name_faculti() const;
	void set_name_faculti(const string &state_name_faculti);

	string get_group_n() const;
	void set_group_n(const string &state_group_n);

	string get_name_building_cafedra() const;
	void set_name_building_cafedra(const string &state_building_cafedra);

	void read_from_screen(string &str, unsigned int n_symbol);
	void read_from_screen(unsigned int &number);
	Student *write_info_student();
};

#endif
