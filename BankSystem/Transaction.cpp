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
