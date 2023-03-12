#include <iostream>

using namespace std;


class Administration
{
private:
	int timework;
public:
	Administration()
	{
		timework = 0;
	}
	Administration(int time)
	{
		timework = time;
	}
	void show_data()
	{
		cout << " Время работы: " << timework << endl;
	}
};

class Teacher
{
private:
	string name;
	string surname;
	string obj;
public:
	Teacher()
	{
		name = ""; surname = ""; obj = "";
	}
	Teacher(string name1, string name2, string object)
	{
		name = name1; surname = name2; obj = object;
	}
	void show_data()
	{
		cout << "Имя: " << name << " Фамилия: " << surname << " Предмет: " << obj << endl;
	}
};


class Student
{
public:
	string name;
	string surname;
	float average_score;

	Student()
	{
		name = ""; surname = ""; average_score = 0;
	}
	Student(string name1, string name2)
	{
		name = name1; surname = name2; average_score = 0;
	}

	void show_data()
	{
		cout << "Имя: " << name << " Фамилия: " << surname << " Средний балл: " << average_score << endl;
	}
};


class Faculty
{
private:
	Student student;
	Administration administration;
	Teacher teacher;

public:
	string title;
	Faculty(string name, string student_name, string student_surname, Administration admin, Teacher person) : student(student_name, student_surname)
	{
		title = name;
		administration = admin;
		teacher = person;
	}

	void show_data()
	{
		cout << "Название факультета: " << title << endl
			<< "Студент - ";
		student.show_data();
		cout << "Преподаватель - ";
		teacher.show_data();
		cout << "Администрация - ";
		administration.show_data();
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	string title;
	string student_name, student_surname;
	string teacher_name, teacher_surname, obj;
	int time;

	cout << "Введите название факультета:\n>";
	cin >> title;
	cout << "Введите имя и фамилию студента:\n>";
	cin >> student_name >> student_surname;
	cout << "Введите время работы администрации (одно число):\n>";
	cin >> time;
	cout << "Введите имя и фамилию преподавателя:\n>";
	cin >> teacher_name >> teacher_surname;
	cout << "Введите предмет, который ведёт преподаватель:\n>";
	cin >> obj;
	cout << endl << endl;

	Administration admin(time);
	Teacher person(teacher_name, teacher_surname, obj);

	Faculty faculty(title, student_name, student_surname, admin, person);
	faculty.show_data();

	return 0;
}
