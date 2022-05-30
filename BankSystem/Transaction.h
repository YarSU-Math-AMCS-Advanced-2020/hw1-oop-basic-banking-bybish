#pragma once
#include "DebitAccount.h"
#include "Card.h"

class Transaction
{
public:
	enum TransactionStatus { IsToProcess, IsProcessing, Done, Denied };

	void get_transaction_status();
	Date get_transaction_date() { return transaction_date; };

	Transaction(DebitAccount* _sender_deb, DebitAccount* _receiver_deb, double _amount, Date _date);
	Transaction(Card* _sender_card, DebitAccount* _receiver_deb, double _amount, Date _date);
	Transaction(DebitAccount* _sender_deb, Card* _receiver_card, double _amount, Date _date);
	Transaction(Card* _sender_card, Card* _receiver_card, double _amount, Date _date);
	void start();

private:
	DebitAccount* sender_deb;
	DebitAccount* receiver_deb;
	double amount;
	Date transaction_date;
	TransactionStatus transaction_status;
};