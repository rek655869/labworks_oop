#include <iostream>

using namespace std;

class Non_working_day
{
public:
	virtual void count_day() = 0;
	virtual void season() = 0;
	virtual ~Non_working_day() {};
};

class Weekends : public Non_working_day //��������
{
public:
	void count_day() override
	{
		cout << "��������: ������ ������ �� 2 �������� - ������� � �����������" << endl;
	}
	void season() override
	{
		cout << "�������� �� ������� �� ������" << endl;
	}
	~Weekends() {};
};

class Holidays : public Non_working_day //���������
{
public:
	void count_day() override
	{
		cout << "���������: ��� ����� ������� � ����������� ����� - 20 ����" << endl;
	}
	void season() override
	{
		cout << "����� ���������� ���������� ���������� - 9 ����, � ������;\n����� �������� ���������� ���������� - 2 ���, � ������" << endl;
	}
	void holidays(int may) //���-�� ���� � ����������� �� ���������
	{
		cout << "���������: � " << may << " ������ ";
		if (may == 1)
			cout << "���������� �������� - 9 ����\n";
		if (may == 2)
			cout << "23 ������� - 3 ���\n";
		if (may == 3)
			cout << "8 ����� - 3 ���\n";
		if (may == 10)
			cout << "���� ��������� �������� - 2 ���\n";
		if ((4 <= may && may <= 9) || (11 <= may && may <= 12))
			cout << "�� ��������\n";
	}
	~Holidays() {};
};

class Vacation : public Non_working_day //������
{
public:
	void count_day() override
	{
		cout << "������: ������������ ���������� - 28 ���� �� ���" << endl;
	}
	void season() override
	{
		cout << "������ ����� ���� ���� � ����� �����" << endl;
	}
	void occasion() //�����
	{
		cout << "������: ������� �� ����" << endl;
	}
	~Vacation() {};
};



int main()
{
	setlocale(LC_ALL, "RUS");
	Weekends weekends;
	Non_working_day* day = &weekends;
	day->count_day();
	day->season();
	Holidays  holidays1;
	Non_working_day* day1 = &holidays1;
	day1->count_day();
	int may = 4;
	holidays1.holidays(may);
	Vacation vacation2;
	Non_working_day* day2 = &vacation2;
	day2->count_day();
	vacation2.occasion();
	return 0;
}