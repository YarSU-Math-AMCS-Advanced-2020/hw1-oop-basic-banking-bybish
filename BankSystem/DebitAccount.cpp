#include "DebitAccount.h"

void DebitAccount::get_currency()
{
	if (currency == Currency::RUB)
		cout << "RUB";
	if (currency == Currency::USD)
		cout << "USD";
	else
		cout << "EURO";
}

DebitAccount::DebitAccount(double _balance, double _limit, Currency _currency)
{
	balance = _balance;
	limit = _limit;
	currency = _currency;
}

void DebitAccount::limit_setting(double _limit)
{
	limit = _limit;
}

Date::Date(int _month, int _day, int _year)
{
	month = _month;
	day = _day;
	year = _year;
}
