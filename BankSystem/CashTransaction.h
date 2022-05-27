 #pragma once
#include "DebitAccount.h"
#include <time.h>

class CashTransaction
{
public:
	enum CashTransactionStatus { Done, Denied };
	enum Type { Withdrawing, Adding };

	void get_cash_transaction_status();
	void get_cash_type();
	time_t get_cash_transaction_time() { return cash_transaction_time; };
	Date get_cash_transaction_date() { return cash_transaction_date; };

	CashTransaction(DebitAccount* _debit_account, double _amount, time_t _cash_transaction_time, Date _cash_transaction_date, Type _cash_transaction_type);
	void start();

private:
	DebitAccount* debit_account;
	double amount;
	time_t cash_transaction_time;
	Date cash_transaction_date;
	CashTransactionStatus cash_transaction_status;
	Type cash_transaction_type;
};