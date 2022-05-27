#include "CashTransaction.h"

void CashTransaction::get_cash_transaction_status()
{
	if (cash_transaction_status == CashTransaction::Done)
		cout << "Done";
	else
		cout << "Denied";
}

void CashTransaction::get_cash_type()
{
	if (cash_transaction_type == Type::Withdrawing)
		cout << "Withdrawing";
	else
		cout << "Adding";
}

CashTransaction::CashTransaction(DebitAccount* _debit_account, double _amount, time_t _cash_transaction_time, Date _cash_transaction_date, Type _cash_transaction_type)
{
	debit_account = _debit_account;
	amount = _amount;
	cash_transaction_time = _cash_transaction_time;
	cash_transaction_date = _cash_transaction_date;
	cash_transaction_type = _cash_transaction_type;
}

void CashTransaction::start()
{
	if (cash_transaction_type == CashTransaction::Type::Adding)
	{
		debit_account->increase(amount);
		cash_transaction_status = CashTransaction::CashTransactionStatus::Done;
	}
	else
	{
		if (debit_account->get_balance() < amount)
		{
			cout << "Недостаточно средств" << endl;
			cash_transaction_status = CashTransaction::CashTransactionStatus::Denied; 
			return;
		}
		if (debit_account->get_limit() < amount)
		{
			cout << "Превышен лимит счёта" << endl;
			cash_transaction_status = CashTransaction::CashTransactionStatus::Denied;
		}
		else
		{
			debit_account->decrease(amount);
			cash_transaction_status = CashTransaction::CashTransactionStatus::Done;
		}
	}
}
