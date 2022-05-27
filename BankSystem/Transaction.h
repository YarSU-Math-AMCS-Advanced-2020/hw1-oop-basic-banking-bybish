#pragma once
#include "DebitAccount.h"
#include <time.h>

class Transaction
{
public:
	enum TransactionStatus { IsToProcess, IsProcessing, Done, Denied };

	void get_transaction_status();
	time_t get_transaction_time() { return transaction_time; };
	Date get_transaction_date() { return transaction_date; };

private:
	DebitAccount* sender_deb;
	DebitAccount* receiver_deb;
	double amount; 
	time_t transaction_time;
	Date transaction_date;
	TransactionStatus transaction_status;
};