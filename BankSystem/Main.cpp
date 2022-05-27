#include <iostream>
#include "Account.h"
#include "CashTransaction.h"

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
	acc.delete_debit_accout(1);																		//�������� �����

	acc.all_debit_account[0]->limit_setting(5000);													//��������� ������ �� �����

	Date date(29,05,2022);
	acc.open_card(date, 0, Card::CardType::Debit, Card::PaymentSystem::MasterBart);					//������ ����� � �����
	acc.open_card(date, 0, Card::CardType::Debit, Card::PaymentSystem::Lisa);

	acc.rebinding_card(0,1);																		//������������ ����� � ������� �����

	acc.delete_card(0);																				//�������� ����� (��� �������� �������� �������)

	acc.all_card[0]->limit_setting(7777);															//��������� ������ ������ ��� �����
	

}