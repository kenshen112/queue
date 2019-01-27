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



bool findObject(const char *ob, const char* recieve)
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

   float price;
   std::cout << "> ";
   std::cin >> data[].input >> data[].numShares >> price;


   if (data[].input == "sell")
   {
	   data[].sellPrice = data[].price;
   }

   else if (data[].input == "buy")
   {
	   data[].purchasePrice = price;
   }
}

float stock::calcProfitLoss()
{ 
   
   
   profitLoss = (sellPrice - purchasePrice) * numShares;

   return this->profitLoss += profitLoss;
}

void stock::display()
{

	//std::cout << "Currently held: " << std::endl;

	//for (somthing with the queue?)
		//{
	         //std::cout << "        Bought " << queue.amount << " shares at " << "$" << queue.profitLoss << std::endl; ? 
        //}

	//if (sold)
	//{

	//std::cout << "Sell History: " << std::endl;
	//for (int i = 0; i < queueSize; i++)
	//{
	
	//std::cout << "        Sold " << queue.amount << " shares at " << "$" << queue.profitLoss << std::endl; ?
	
	//}
	
	//}


}
