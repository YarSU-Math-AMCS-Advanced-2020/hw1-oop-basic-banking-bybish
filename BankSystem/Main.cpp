#include <iostream>
#include "Account.h"
#include "CashTransaction.h"
#include "Transaction.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Account acc;
	LegalEntity baza("McDonald�s", "8961242451", "�. ��������� ��. ������������� ��-� ��� 11");
	LegalEntity beze("Mc", "8961242451", "�. ��������� ��. ������������� ��-� ��� 11");
	acc.reg_legal_entity(baza);																		//����������� ��������
	acc.change_legal_entity(beze);																	//��������� ���������� � ������� 

	acc.open_debit_account();																		//�������� �����
	acc.open_debit_account(DebitAccount::Currency::RUB);
	acc.open_debit_account(DebitAccount::Currency::EURO);
	acc.open_debit_account(DebitAccount::Currency::USD);

	acc.delete_debit_accout(1);																		//�������� �����

	acc.all_debit_account[0]->limit_setting(5000);													//��������� ������ �� �����

	Date date(29,05,2022);
	acc.open_card(date, 0, Card::CardType::Debit, Card::PaymentSystem::MasterBart);					//������ ����� � �����
	acc.open_card(date, 0, Card::CardType::�redit, Card::PaymentSystem::Lisa);
	acc.open_card(date, 1, Card::CardType::Debit, Card::PaymentSystem::MasterBart);

	acc.rebinding_card(0,1);																		//������������ ����� � ������� �����

	acc.delete_card(0);																				//�������� ����� (��� �������� �������� �������)

	acc.all_card[0]->limit_setting(7777);															//��������� ������ ������ ��� �����
	

	CashTransaction replenishment(acc.all_debit_account[0], 6000.5, date, CashTransaction::Type::Adding); //����� �����
	replenishment.start();

	CashTransaction withdrawal(acc.all_debit_account[0], 5100, date, CashTransaction::Type::Withdrawing); //���� �����
	withdrawal.start();

	Transaction  transfer1(acc.all_debit_account[0], acc.all_debit_account[1], 3000, date);			//������� ����� �� ������ ����
	transfer1.start();

	Transaction  transfer2(acc.all_card[1], acc.all_card[0], 500, date);							//������� ����� �� ������ ���� ��� ������ ����
	transfer2.start();

	acc.print_deb_account();
	//acc.print_card();
}