#include "DebitAccount.h"

string DebitAccount::get_currency_rep()
{
	if (currency == Currency::RUB)
		return "RUB";
	else
	{
		if (currency == Currency::USD)
			return "USD";
		else
			return "EUR";
	}
	
}

DebitAccount::Currency DebitAccount::get_currency()
{
	return currency;
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

void DebitAccount::print_info()
{
	cout << "" << get_balance() << endl;
	cout << "" << get_limit() << endl;
	cout << "" << get_currency_rep() << endl;
	cout << endl << endl;
}

Date::Date(int _month, int _day, int _year)
{
	month = _month;
	day = _day;
	year = _year;
}
