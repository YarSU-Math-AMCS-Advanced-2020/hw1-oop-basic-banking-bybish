#include "Card.h"

Card::Card(Date _expiration_time, DebitAccount* _debit_account, double _limit_card, CardType _card_type, PaymentSystem _payment_system)
{
	expiration_time = _expiration_time;
	debit_account = _debit_account;
	limit_card = _limit_card;
	card_type = _card_type;
	payment_system = _payment_system;
}

void Card::set_debit_account(DebitAccount* _debit_account)
{
	debit_account = _debit_account;
}

void Card::limit_setting(double _limit)
{
	limit_card = _limit;
}

void Card::print_info()
{
	cout << debit_account->get_balance() << endl;
	cout << limit_card << endl;
	if (card_type == CardType::Debit)
		cout << "Debit" << endl;
	else
		cout << "Credit" << endl;

	if (payment_system == PaymentSystem::HoMiR)
		cout << "HoMir" << endl;
	else
	{
		if(payment_system == PaymentSystem::Lisa)
			cout << "Lisa" << endl;
		else
			cout << "MasterBart" << endl;
	}
	cout << endl << endl;
}
