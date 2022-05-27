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
	delete debit_account;
	debit_account = _debit_account;
}

void Card::limit_setting(double _limit)
{
	limit_card = _limit;
}
