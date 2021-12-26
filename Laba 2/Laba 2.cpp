/* Лабы 2 - 4
Весь ввод/вывод должен осуществляться только внутри функции main().

		Передача в функции объектов типа класс должна осуществляться через указатель либо ссылку на объект.

		Все другие нестатические данные должны передаваться функциям через параметры.

		Все нестатические элементы класса должны иметь закрытый атрибут доступа. Доступ извне к таким элементам должен
		осуществляться через функции-элементы класса.

Определите элементы-функции, которые читают дату из потока ввода, выводят дату.
 Определите дружественную функцию, которая вычисляет разницу в днях между двумя датами.
*/
#include<iostream>
using namespace std;

class Date
{

private: 

	int day;
	int month;
	int year;

public:

	Date() {

		day = 0;
		month = 0;
		year = 0;
	}

	// Конструктор с параметрами
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// Конструктор копирования
	Date(const Date& date) :
		day(date.day), month(date.month), year(date.year)
	{

	}

	Date* dataInput(Date* array, int numberOfDates)
	{

		for (int i = 0; i < numberOfDates; i++)
		{
			cout << i + 1 << ": " << endl;
			cout << "Enter day: "; cin >> array[i].day; cout << endl;
			cout << "Enter month: "; cin >> array[i].month; cout << endl;
			cout << "Enter year: "; cin >> array[i].year; cout << endl;
		}
		return array;
	}

	Date* outData(Date* array, int numberOfDates)
	{
		for (int i = 0; i < numberOfDates; i++)
		{
			cout << array[i].day << "." << array[i].month << "." << array[i].year << endl;
		}
		return array;
	}

	friend void difference(Date* array, int numberDates)
	{
		int days;
		int oneData = 0;
		int twoData = 0;
		int difOfDays = 0;
		int difOfMonth = 0;
		int difOfYears = 0;

		int temp1Day = array[oneData].day;
		int temp2Day = array[twoData].day;
		int temp1Year = array[oneData].year;
		int temp2Year = array[twoData].year;
		int temp1Month = array[oneData].month;
		int temp2Month = array[twoData].month;

		cout << "Between what dates do you want to know the difference in days: " << endl;
		cout << "First: ";  cin >> oneData;
		cout << "Second: ";  cin >> twoData;

		oneData--; twoData--;

		// Года
		if (array[oneData].year >= array[twoData].year) difOfYears = array[oneData].year - array[twoData].year;
		else difOfYears = array[twoData].year - array[oneData].year;

		if (array[oneData].year >= array[twoData].year)
		{
			temp1Year = array[oneData].year;
			while (array[oneData].year > array[twoData].year)
			{
				if (array[oneData].year % 4 == 0 || array[oneData].year % 400 == 0)
				{
					difOfDays += 366;
				}
				else
				{
					difOfDays += 365;
				}
				array[oneData].year--;
			}
			array[oneData].year = temp1Year;
		}

		else
		{
			temp2Year = array[twoData].year;
			while (array[twoData].year > array[oneData].year)
			{
				if (array[twoData].year % 4 == 0 || array[twoData].year % 400 == 0)
				{
					difOfDays += 366;
				}
				else
				{
					difOfDays += 365;
				}
				array[twoData].year--;
			}
			array[twoData].year = temp2Year;
		}

		// Month and days
		int count;
		int countOfMonth;
		if (array[oneData].month == array[twoData].month) countOfMonth = 1; // first option
		if (array[oneData].month > array[twoData].month) countOfMonth = 2; // second option
		if (array[oneData].month < array[twoData].month) countOfMonth = 3; // third option 

		switch (countOfMonth)
		{
		case 1:
		{
			if (array[oneData].day <= array[twoData].day) {
				temp1Day = array[oneData].day;
				while (array[oneData].day != array[twoData].day) {
					array[oneData].day++;
					difOfDays++;
				}
				array[oneData].day = temp1Day;
			}

			else {
				temp2Day = array[twoData].day;
				while (array[twoData].day != array[oneData].day) {
					array[twoData].day++;
					difOfDays++;
				}
				array[twoData].day = temp2Day;
			}

			break;
		}
		case 2:
		{

			temp2Month = array[twoData].month;
			while (array[twoData].month <= array[oneData].month)
			{
				switch (array[twoData].month)
				{
				case 1: days = 31; break;
				case 2:
					if (array[twoData].year % 4 == 0 || array[twoData].year % 400 == 0) {
						days = 29;
					}
					else {
						days = 28;
					}
					break;
				case 3: days = 31; break;
				case 4: days = 30; break;
				case 5: days = 31; break;
				case 6: days = 30; break;
				case 7: days = 31; break;
				case 8: days = 31; break;
				case 9: days = 30; break;
				case 10: days = 31; break;
				case 11: days = 30; break;
				case 12: days = 31; break;
				default: cout << "This month is missing!" << endl; break;
				}

				// first month pass
				if (temp2Month == array[twoData].month) {
					temp2Day = array[twoData].day;
					while (array[twoData].day != days) {
						array[twoData].day++;
						difOfDays++;
					}
					array[twoData].day = temp1Day;
				}

				// the passage of not the first and not the last month
				if (temp2Month != array[twoData].month && array[oneData].month != array[twoData].month) {
					difOfDays += days;
				}

				// last month pass
				if (array[oneData].month == array[twoData].month)
				{
					for (count = 0; count < array[oneData].day; count++) {
						difOfDays++;
					}
				}

				array[twoData].month++;
			}

			array[oneData].month = temp1Month;
			break;
		}

		case 3:
		{
			temp1Month = array[oneData].month;
			while (array[oneData].month <= array[twoData].month)
			{
				switch (array[oneData].month)
				{
				case 1: days = 31; break;
				case 2:
					if (array[oneData].year % 4 == 0 || array[oneData].year % 400 == 0) {
						days = 29;
					}
					else {
						days = 28;
					}
					break;
				case 3: days = 31; break;
				case 4: days = 30; break;
				case 5: days = 31; break;
				case 6: days = 30; break;
				case 7: days = 31; break;
				case 8: days = 31; break;
				case 9: days = 30; break;
				case 10: days = 31; break;
				case 11: days = 30; break;
				case 12: days = 31; break;
				default: cout << "This month is missing!" << endl; break;
				}

				// first month pass
				if (temp1Month == array[oneData].month) {
					temp1Day = array[oneData].day;
					while (array[oneData].day != days) {
						array[oneData].day++;
						difOfDays++;
					}
					array[oneData].day = temp1Day;
				}

				// the passage of not the first and not the last month
				if (temp1Month != array[oneData].month && array[oneData].month != array[twoData].month) {
					difOfDays += days;
				}

				// last month pass
				if (array[oneData].month == array[twoData].month)
				{
					for (count = 0; count < array[twoData].day; count++) {
						difOfDays++;
					}
				}

				array[oneData].month++;
			}
			break;
		}
		}
		cout << "Your difference in days: " << difOfDays << endl;
	}



};


void main()
{
	int numberOfDates;
	cout << "Enter number of dates: "; cin >> numberOfDates; cout << endl;
	Date* array = new Date[numberOfDates];
	array->dataInput(array, numberOfDates);
	cout << "Your data:" << endl;
	array->outData(array, numberOfDates);
	difference(array, numberOfDates);
}

