#pragma once
#include "DebitAccount.h"

class Card
{
public:
	enum class CardType { Debit, Ñredit};
	enum class PaymentSystem { Lisa, MasterBart, HoMiR };

	Card(Date _expiration_time, DebitAccount* _debit_account, double _limit_card, CardType _card_type, PaymentSystem _payment_system);

	DebitAccount* get_debit_account() { return debit_account; };

	void set_debit_account(DebitAccount* _debit_account);
	void limit_setting(double _limit); 

private:
	Date expiration_time;
	DebitAccount* debit_account;
	double limit_card;
	CardType card_type;
	PaymentSystem payment_system;
};