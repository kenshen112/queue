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
#include <stdlib.h>
#include <stdio.h>
using namespace std; // Bad CS teacher's don't make me sick stack overflow on you



bool findObject(const char *ob, const char* recieve)
{
	if (strstr(recieve, ob) != NULL)//getting error in linux with this one
	{
		return true;
	}

	else
	{
		return false;
	}
}


stock::stock()
{

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

   stockData temp;
   float price;
   string s;

   //string to float var
   string sf;
   //main input loop for stock
   do
   {
      std::cout << "> ";
      std::cin >> s;
      std::string delimiter = " ";
      std::string token = s.substr(0, s.find(delimiter));

      if (findObject(temp.input.c_str(), "sell"))
      {
         sf = (token[1]);
         temp.sellPrice = std::stof(sf);
      }

	  else if (findObject(temp.input.c_str(), "buy")) 
      {
         sf = (token[1]);
         temp.purchasePrice = std::stof(sf);
      }
      else if (findObject(temp.input.c_str(), "display"))
      {
         display();
      }

      data.push(temp);
   } while (temp.input != "quit");

}

float stock::calcProfitLoss()
{ 



   this->data.front().profitLoss = (data.front().sellPrice - data.front().purchasePrice) * data.front().numShares;

   return this->data.front().profitLoss += data.front().profitLoss;
   
}

void stock::display()
{
	std::cout << "Currently held: " << std::endl;

	queue <stockData> temp = data;


	for (int i = 0; i < temp.size(); i++)	
	{
	         std::cout << "        Bought " << temp.front().amount << " shares at " << "$" << temp.front().profitLoss << std::endl;  
			 temp.pop();
	}

	return;

	//if (sold)
	//{

	//std::cout << "Sell History: " << std::endl;
	//for (int i = 0; i < queueSize; i++)
	//{
	
	//std::cout << "        Sold " << queue.amount << " shares at " << "$" << queue.profitLoss << std::endl; ?
	
	//}
	
	//}


}
