#include <iostream>
#include "Account.h"
#include "CashTransaction.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Account acc;
	LegalEntity baza("McDonald’s", "8961242451", "г. Ярославль ул. Ленинградский пр-т дом 11");
	LegalEntity beze("Mc", "8961242451", "г. Ярославль ул. Ленинградский пр-т дом 11");
	acc.reg_legal_entity(baza);																		//регистрация аккаунта
	acc.change_legal_entity(beze);																	//изменение информации о клиенте 

	acc.open_debit_account();																		//Открытие счёта
	acc.open_debit_account(DebitAccount::Currency::RUB);
	acc.open_debit_account(DebitAccount::Currency::EURO);
	acc.delete_debit_accout(1);																		//Закрытие счёта

	acc.all_debit_account[0]->limit_setting(5000);													//Установка лимита на счёте

	Date date(29,05,2022);
	acc.open_card(date, 0, Card::CardType::Debit, Card::PaymentSystem::MasterBart);					//Выпуск карты к счёту
	acc.open_card(date, 0, Card::CardType::Debit, Card::PaymentSystem::Lisa);

	acc.rebinding_card(0,1);																		//Перепривязка карты к другому счёту

	acc.delete_card(0);																				//Закрытие карты (без перевода денежных средств)

	acc.all_card[0]->limit_setting(7777);															//Установка лимита снятия для карты
	

}