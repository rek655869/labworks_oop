#include <iostream>

using namespace std;

class Non_working_day
{
public:
	virtual void count_day() = 0;
	virtual void season() = 0;
	virtual ~Non_working_day() {};
};

class Weekends : public Non_working_day //выходные
{
public:
	void count_day() override
	{
		cout << "Выходные: каждую неделю по 2 выходных - суббота и воскресенье" << endl;
	}
	void season() override
	{
		cout << "Выходные не зависят от сезона" << endl;
	}
	~Weekends() {};
};

class Holidays : public Non_working_day //праздники
{
public:
	void count_day() override
	{
		cout << "Праздники: без учёта субботы и воскресенья всего - 20 дней" << endl;
	}
	void season() override
	{
		cout << "Самый длительный промежуток праздников - 9 дней, в январе;\nСамый короткий промежуток праздников - 2 дня, в ноябре" << endl;
	}
	void holidays(int may) //кол-во дней в зависимости от праздника
	{
		cout << "Праздники: в " << may << " месяце ";
		if (may == 1)
			cout << "новогодние каникулы - 9 дней\n";
		if (may == 2)
			cout << "23 февраля - 3 дня\n";
		if (may == 3)
			cout << "8 марта - 3 дня\n";
		if (may == 10)
			cout << "День народного единства - 2 дня\n";
		if ((4 <= may && may <= 9) || (11 <= may && may <= 12))
			cout << "не отдыхаем\n";
	}
	~Holidays() {};
};

class Vacation : public Non_working_day //Отпуск
{
public:
	void count_day() override
	{
		cout << "Отпуск: максимальное количество - 28 дней за год" << endl;
	}
	void season() override
	{
		cout << "Отпуск может быть взят в любой сезон" << endl;
	}
	void occasion() //повод
	{
		cout << "Отпуск: поездка на море" << endl;
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