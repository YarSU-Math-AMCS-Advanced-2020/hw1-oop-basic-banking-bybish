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
	Date get_cash_transaction_date() { return cash_transaction_date; };

	CashTransaction(DebitAccount* _debit_account, double _amount, Date _date, Type _type);
	void start();

private:
	DebitAccount* debit_account;
	double amount;
	Date cash_transaction_date;
	CashTransactionStatus cash_transaction_status;
	Type cash_transaction_type;
};