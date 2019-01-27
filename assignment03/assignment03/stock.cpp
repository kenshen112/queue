/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Tim O'Barr and Kenyon Bunker
 **********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
#include <vector>
#include <string>
#include <sstream>
#include <iterator>


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

   stockData stocks;
   string str;
   string test = "This is making me mad!";
   string inputArr[4];  //array for input tokens

   //main input loop for stock
   do
   {
      std::cout << "> ";
      std::getline(cin, str);

      std::istringstream stm(str);
              
      string inputPart;          //parts of the array
      int i = 0;                 //counter for while
      while (stm >> inputPart) // read white-space delimited tokens one by one 
      {
         inputArr[i] = inputPart;
         i++;
      }

      // 0 = selection :: 1 = numShares :: 2 = price
      if (inputArr[0] == "sell")
      {

         stocks.numShares = std::stof(inputArr[1]);
         stocks.purchasePrice = std::stof(inputArr[2]);
      }

	  else if (inputArr[0] == "buy")
      {
         stocks.numShares = std::stof(inputArr[1]);
         stocks.purchasePrice = std::stof(inputArr[2]);
      }
      else if (inputArr[0] == "display")
      {
         display();
      }

      data.push(stocks);
   } while (inputArr[0] != "quit");

}

vector<string> stock::split(string s, char delimiter)
{
   vector<string> internal;
   stringstream ss(s); // Turn the string into a stream.
   string tok;

   while (getline(ss, tok, delimiter)) {
      internal.push_back(tok);
   }

   return internal;
}

float stock::calcProfitLoss()
{ 

   this->data.front().profitLoss = (data.front().sellPrice - data.front().purchasePrice) * data.front().numShares;

   return this->data.front().profitLoss += data.front().profitLoss;
   
}

void stock::display()
{
	std::cout << "Currently held: " << std::endl;

	queue <stockData> stocks = data;


	for (int i = 0; i < stocks.size(); i++)	
	{
	         std::cout << "        Bought " << stocks.front().amount << " shares at " << "$" << stocks.front().profitLoss << std::endl;  
			 stocks.pop();
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
