#include <iostream>

using namespace std;

//необходимые нам структуры(легкий уровень);
struct Birthday
{
	int year;
};

struct Worker
{
	char surname[56];
	char position[32];
	long float salary;
	char education[32];
	Birthday date;
};

void easy()
{
	int year = 0;

	const int size = 2;

	Worker arr[size];

	cout << endl << "Вывести информацию о наймладшем работнике" << endl << endl;

	//цикл для ввода элементов структур;
	for (int i = 0; i < size; i++)
	{
		cout << "Работник под номером " << i + 1 << endl << endl;
		cout << "Введите фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].surname, 56);
		cout << endl;

		do {
			do {
				cout << "Введите год рождения: ";
				cin >> arr[i].date.year;
				cout << endl;
			} while (arr[i].date.year < 1900);
		} while (arr[i].date.year > 2010);

		cout << "Введите должность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].position, 32);
		cout << endl;

		cout << "Введите зарплату: ";
		cin >> arr[i].salary;
		cout << endl;

		cout << "Введите образование: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].education, 32);
		cout << endl << endl;
	}

	//определяем наймладшего работника;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].date.year > arr[year].date.year)
		{
			year = i;
		}
	}

	cout << "Наймладший работник родился в " << arr[year].date.year << endl << endl;

	//выводим о нем информацию;
	cout << "Информация об этом работнике: " << endl;
	cout << "Фамилия: " << arr[year].surname << ", Год рождения: " << arr[year].date.year << endl;
	cout << "Должность: " << arr[year].position << ", Зарплата: " << arr[year].salary << " грн" << endl;
	cout << "Образование: " << arr[year].education << endl;
	cout << endl;
}

//необходимые структуры(средний уровень);
struct Date
{
	int day;
	int month;
	int year;
};

struct Player
{
	char surname[56];
	Date birthday;
	char club[56];
	char role[16];
	int games;
	char place[32];
	long long int time = 0;
};

void medium()
{
	int day, month, count, count1 = 0, count2 = 0, life_time = 20, year = 2020;

	long long int full_time = 0, twenty_years_time = 0;

	const int size = 2;

	Player arr1[size];

	cout << endl << "Вывести информацию об игроках младше 20-ти лет и сыгравших более 40 игр" << endl << endl;

	//вводим информацию об игроках;
	for (int i = 0; i < size; i++)
	{
		count = 0;

		cout << "Игрок под номером " << i + 1 << endl << endl;
		cout << "Введите фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr1[i].surname, 56);
		cout << endl;

		cout << "Введите клуб: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr1[i].club, 56);
		cout << endl;

		cout << "Введите амплуа: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr1[i].role, 16);
		cout << endl;

		do {
			cout << "Введите количество игр: ";
			cin >> arr1[i].games;
			cout << endl;
		} while (arr1[i].games < 0);

		cout << "Введите место рождения: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr1[i].place, 32);
		cout << endl;

		//проверка на корректность даты учитывая высокостный год;
		do
		{
			cout << "Введите день рождения: ";
			cin >> arr1[i].birthday.day;
			cout << endl;
			cout << "Введите месяц: ";
			cin >> arr1[i].birthday.month;
			cout << endl;

			do {
				cout << "Введите год: ";
				cin >> arr1[i].birthday.year;
				cout << endl;
			} while (arr1[i].birthday.year > 2014);

			if (arr1[i].birthday.month == 1 || arr1[i].birthday.month == 3 || arr1[i].birthday.month == 5 || arr1[i].birthday.month == 7 || arr1[i].birthday.month == 8 || arr1[i].birthday.month == 10 || arr1[i].birthday.month == 12)
			{
				if (arr1[i].birthday.day <= 31 && arr1[i].birthday.day > 0)
				{
					count++;
				}
			}

			if (arr1[i].birthday.month == 4 || arr1[i].birthday.month == 6 || arr1[i].birthday.month == 9 || arr1[i].birthday.month == 11)
			{
				if (arr1[i].birthday.day <= 30 && arr1[i].birthday.day > 0)
				{
					count++;
				}
			}

			else
			{

				if (arr1[i].birthday.month == 2 && arr1[i].birthday.year % 4 != 0)
				{
					if (arr1[i].birthday.day <= 28 && arr1[i].birthday.day > 0)
					{
						count++;
					}
				}

				else
				{
					if (arr1[i].birthday.year % 400 == 0)
					{
						if ((arr1[i].birthday.day <= 29) && (arr1[i].birthday.day > 0))
						{
							count++;
						}
					}

					else
					{
						if ((arr1[i].birthday.year % 100 == 0) && (arr1[i].birthday.year % 400 != 0))
						{
							if ((arr1[i].birthday.day == 28) && (arr1[i].birthday.day > 0))
							{
								count++;
							}
						}

						else
						{
							if ((arr1[i].birthday.year % 4 == 0) && (arr1[i].birthday.year % 100 != 0))
							{
								if ((arr1[i].birthday.day <= 29) && (arr1[i].birthday.day > 0))
								{
									count++;
								}
							}
						}
					}
				}
			}

		} while (count < 1);
	}

	//необходимо ввести настоящее время что-бы отталкиваться от него(год уже известен как 2020);
	do
	{
		cout << "Введите нынешний день: ";
		cin >> day;
		cout << endl;
		cout << "Введите нынешний месяц: ";
		cin >> month;
		cout << endl;

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31 && day > 0)
			{
				count1++;
			}
		}

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30 && day > 0)
			{
				count1++;
			}
		}

		else
		{
			if (month == 2 && year % 4 != 0)
			{
				if (day <= 28 && day > 0)
				{
					count1++;
				}
			}

			else
			{
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
					{
						count1++;
					}
				}

				else
				{
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
						{
							count1++;
						}
					}

					else
					{
						if ((year % 4 == 0) && (year % 100 != 0))
						{
							if ((day <= 29) && (day > 0))
							{
								count1++;
							}
						}
					}
				}
			}
		}

	} while (count1 < 1);

	//переводим все 2020 лет в дни учитывая высокостные годы;
	for (int i = 1; i <= year; i++)
	{
		if (i % 4 != 0)
		{
			full_time += 365;
		}

		if (i % 4 == 0)
		{
			full_time += 366;
		}
	}

	//прибавляем введенные месяц и день(большая часть месяцев имеют 31 день поэтому берем это число);
	full_time += month * 31 + day;

	//то же самое проделываем с датой рождения каждого игрока;
	for (int i = 0; i < size; i++)
	{
		int count2 = 0;
		count2 = arr1[i].birthday.year;

		for (int j = 1; j <= count2; j++)
		{
			if (j % 4 != 0)
			{
				arr1[i].time += 365;
			}

			if (j % 4 == 0)
			{
				arr1[i].time += 366;
			}
		}

		arr1[i].time += arr1[i].birthday.month * 31 + arr1[i].birthday.day;
	}

	//игрок должен быть младше 20-ти лет - разбиваем и это число на дни;
	for (int i = 0; i < life_time; i++)
	{
		if (i % 4 != 0)
		{
			twenty_years_time += 365;
		}

		if (i % 4 == 0)
		{
			twenty_years_time += 366;
		}
	}

	cout << endl << "Информация об игроках младше 20 лет и сыгравших более 40 матчей: " << endl << endl;

	//находим разницу между нынешним временем и 20-ю годами, если время жизни игрока больше разницы - ему меньше 20 лет;
	for (int i = 0; i < size; i++)
	{
		int different = full_time - twenty_years_time;
		if (arr1[i].time > different && arr1[i].games > 40)
		{
			cout << "Игрок под номером " << i + 1 << endl;
			cout << "Фамилия: " << arr1[i].surname << ", Дата рождения: " << arr1[i].birthday.day << "." << arr1[i].birthday.month << "." << arr1[i].birthday.year << endl;
			cout << "Амплуа: " << arr1[i].role << ", Кол-во матчей: " << arr1[i].games << ", Место рождения: " << arr1[i].place << endl << endl;
			count2++;
		}

		if (i == size - 1 && count2 == 0)
		{
			cout << "Нет таких игроков" << endl << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	int a, count3 = 0;

	do
	{

		cout << "Введите номер задания: 1(easy) или 2(medium): ";

		cin >> a;

		if (a == 1)
		{
			easy();
			count3++;
		}

		if (a == 2)
		{
			medium();
			count3++;
		}

	} while (count3 == 0);
}