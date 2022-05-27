#include "Account.h"

void Account::set_login(string _login)
{
	login = _login;
}

void Account::set_password(string _password)
{
	password = _password;
}

void Account::reg_individual(Individual _individual)
{
	string temp;
	cout << "Введите логин:";
	cin >> temp;
	set_login(temp);
	cout << "Введите пароль:" << endl;
	cin >> temp;
	set_password(temp);
	individual = _individual;
}

void Account::reg_legal_entity(LegalEntity _legal_entity)
{
	string temp;
	cout << "Введите логин: ";
	cin >> temp;
	set_login(temp);
	cout << "Введите пароль: ";
	cin >> temp;
	cout << endl << endl;
	set_password(temp);
	legal_entity = _legal_entity;
}

void Account::change_individual(Individual _individual)
{
	individual = _individual;
}

void Account::change_legal_entity(LegalEntity _legal_entity)
{
	legal_entity = _legal_entity;
}

void Account::open_debit_account()
{
	cout << "Выберете валюту" << endl << "1.USD  2.EURO   3.RUB" << endl;
	int temp = 4;
	while (temp != 1 && temp != 2 && temp != 3)
	{
		cout << "Введите номер соответствующей валюты: " << endl;
		cin >> temp;
	}
	if (temp == 1)
		all_debit_account.push_back(new DebitAccount(0, 100000, DebitAccount::Currency::USD));
	if (temp == 2)
		all_debit_account.push_back(new DebitAccount(0, 100000, DebitAccount::Currency::EURO));
	if (temp == 3)
		all_debit_account.push_back(new DebitAccount(0, 100000, DebitAccount::Currency::RUB));
	
}

void Account::open_debit_account(DebitAccount::Currency _currency)
{
	all_debit_account.push_back(new DebitAccount(0, 100000, _currency));
}

void Account::delete_debit_accout(int number_deb)
{
	if (all_debit_account.size() <= number_deb || number_deb < 0)
	{
		cout << "Ошибка, такого счёта нет";
		return;
	}

	for (int i = 0; i < all_card.size(); i++)
		if (all_card[i]->get_debit_account() == all_debit_account[number_deb])
		{
			delete all_card[i];
			all_card.erase(all_card.begin() + i);
		}

	delete all_debit_account[number_deb];
	all_debit_account.erase(all_debit_account.begin() + number_deb);

}

void Account::open_card(Date _date, int _number, Card::CardType _type, Card::PaymentSystem _paymen_system)
{
	all_card.push_back(new Card(_date, all_debit_account[_number], all_debit_account[_number]->get_limit(), _type, _paymen_system));
}

void Account::rebinding_card(int _number_card, int _number_deb)
{
	all_card[_number_card]->set_debit_account(all_debit_account[_number_deb]);
}

void Account::delete_card(int _number_card)
{
	delete all_card[_number_card];
	all_card.erase(all_card.begin() + _number_card);
}



