#include "Transaction.h"

void Transaction::get_transaction_status()
{
	if (transaction_status == Transaction::IsToProcess)
		cout << "IsToProcess";
	if (transaction_status == Transaction::IsProcessing)
		cout << "IsProcessing";
	if (transaction_status == Transaction::Done)
		cout << "Done";
	else
		cout << "Denied";
}

Transaction::Transaction(DebitAccount* _sender_deb, DebitAccount* _receiver_deb, double _amount, Date _date)
{
	sender_deb = _sender_deb;
	receiver_deb = _receiver_deb;
	amount = _amount;
	transaction_date = _date;
}

Transaction::Transaction(Card* _sender_card, DebitAccount* _receiver_deb, double _amount, Date _date)
{
	sender_deb = _sender_card->get_debit_account();
	receiver_deb = _receiver_deb;
	amount = _amount;
	transaction_date = _date;
}

Transaction::Transaction(DebitAccount* _sender_deb, Card* _receiver_card, double _amount, Date _date)
{
	sender_deb = _sender_deb;
	receiver_deb = _receiver_card->get_debit_account();
	amount = _amount;
	transaction_date = _date;
}

Transaction::Transaction(Card* _sender_card, Card* _receiver_card, double _amount, Date _date)
{
	sender_deb = _sender_card->get_debit_account();
	receiver_deb = _receiver_card->get_debit_account();
	amount = _amount;
	transaction_date = _date;
}

void Transaction::start()
{
	if (sender_deb->get_limit() < amount)
	{
		cout << "Превышен лимит карты" << endl;;
		transaction_status = TransactionStatus::Denied;
		return;
	}
	if (sender_deb->get_balance() < amount)
	{
		cout << "Превышен баланс карты"<<endl;
		transaction_status = TransactionStatus::Denied;
		return;
	}
	if (sender_deb->get_currency() != receiver_deb->get_currency())
	{
		cout << "Разные валюты"<<endl;
		transaction_status = TransactionStatus::Denied;
		return;
	}
	sender_deb->decrease(amount);
	receiver_deb->increase(amount);
	transaction_status = TransactionStatus::Done;
}


