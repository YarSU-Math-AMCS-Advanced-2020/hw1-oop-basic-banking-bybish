#pragma once
#include "Card.h"
#include "Client.h"
#include <vector>

class Account 
{
public:
	Individual individual;
	LegalEntity legal_entity;
	vector<DebitAccount*> all_debit_account;
	vector<Card*> all_card;

	Account() {};
	
	DebitAccount* get_debit_account(int number) { return all_debit_account[number]; };

	void set_login(string _login);
	void set_password(string _password);
	string get_login() { return login; };
	string get_password() { return password; };

	void reg_individual(Individual _individual);
	void reg_legal_entity(LegalEntity _legal_entity);
	void change_individual(Individual _individual);
	void change_legal_entity(LegalEntity _legal_entity);

	void open_debit_account();
	void open_debit_account( DebitAccount::Currency );
	void delete_debit_accout(int number_deb);

	void open_card(Date _date, int _number, Card::CardType _type, Card::PaymentSystem _paymen_system);
	void rebinding_card( int _number_card, int _number_deb);
	void delete_card(int _number_card);

	void print_deb_account();
	void print_deb_account(int number);

	void print_card();
	void print_card(int number);

private:
	string login;
	string password;
};