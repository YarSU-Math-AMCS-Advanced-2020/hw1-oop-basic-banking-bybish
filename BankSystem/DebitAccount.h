#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	int month=1, day=1, year=2002;
	Date() {};
	Date(int _month, int _day, int year);
};

class DebitAccount
{
public:
	enum class Currency { USD, EUR, RUB };

	double get_balance() { return balance; };
	double get_limit() { return limit; };
	string get_currency_rep();
	Currency get_currency();
	void increase(double amount) { balance += amount; };
	void decrease(double amount) { balance -= amount; };
	DebitAccount(double _balance, double _limit, Currency _currency);

	void limit_setting(double _limit);

	void print_info();

private:
	double balance;
	double limit;
	Currency currency;
};