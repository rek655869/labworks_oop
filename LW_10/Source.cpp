#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");


    thread t1([&]()
        {
            ifstream file("text1.txt");
            long int count = 0;
            char sym;

            while (file >> sym)
            {
                count += sym;
            }

            cout << "Контрольная сумма файла 1: " << count << endl;
        });

    thread t2([&]()
        {
            ifstream file("text2.txt"); 
            long int count = 0;
            char sym;

            while (file >> sym)
            {
                count += sym;
            }

            cout << "Контрольная сумма файла 2: " << count << endl;
        });

    t1.join();
    t2.join();

	return 0;
}