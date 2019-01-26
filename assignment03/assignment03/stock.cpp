/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Tim O'Barr and Kenyon Bunker
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std; // Bad CS teacher's don't make me sick stack overflow on you



bool findObject(char *ob, char recieve[])
{
	if (strstr(recieve, ob) != NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}



/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stock::stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   std::string input;




}

float stock::calcProfitLoss()
{
   
   int batchesArray[];
   (sellPrice - purchasePrice) * numShares;

   return profitLoss;
}

stock::stock()
{
   numSellBatches = 0;
}
