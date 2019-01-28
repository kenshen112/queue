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
//#include <vector>
#include <string>
//#include <sstream>
//#include <iterator>

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
/************************************************
* Default Constructor
***********************************************/
stock::stock()
{
   sold = false;
   boughtCounter = 0;
   soldCounter = 0;
   proceeds = 0;
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

   stockData sData;     //holds stock data
   string str;          //input data
   string inputArr[4];  //array for input tokens
   cin.ignore();        //because cin is weird

   //main input loop for stock
   do
   {
      
      std::cout << "> ";
      
      std::getline(std::cin, str);

      std::istringstream stm(str);
              
      string inputPart;          //parts of the array
      int i = 0;                 //counter for while
      while (stm >> inputPart) // read white-space delimited tokens one by one 
      {
         inputArr[i] = inputPart;
         i++;
      }

      // 0 = selection :: 1 = numShares :: 2 = stock price
      if (inputArr[0] == "sell")
      {

         sData.numShares = atof(inputArr[1].c_str());
         sData.purchasePrice = atof(inputArr[2].c_str());
         sold = true;
         sellHistory.push_back(sData);
         //data.pop();
	      soldCounter++;     
      }


      else if (inputArr[0] == "buy")
      {
         sData.numShares = atof(inputArr[1].c_str());
         sData.purchasePrice = atof(inputArr[2].c_str());
         data.push(sData);
	 boughtCounter++;
      }
      else if (inputArr[0] == "display")
      {
         display();
      }

   } while (inputArr[0] != "quit");

}
/***********************************************
* STOCK :: calcProfitLoss
* Calculates the profit, loss and proceeds
* associated with buying and selling stocks
***********************************************/
float stock::calcProfitLoss()
{ 
   this->data.front().profitLoss = (data.front().sellPrice - data.front().purchasePrice) * data.front().numShares;

   //return this->data.front().profitLoss += data.front().profitLoss;
   return 0.0f; 
}

/***********************************************
* STOCK :: display
* displays stock data
***********************************************/
void stock::display()
{
	std::cout << "Currently held:" << std::endl;

	queue <stockData> stocks = data;

	for (int i = 0; i < boughtCounter; i++)	
	{
	         std::cout << "\tBought " << stocks.front().numShares << " shares at " << stocks.front().purchasePrice << std::endl;
			 stocks.pop();
	}

	std::cout << "Proceeds: " << proceeds << std::endl;
	
       if (sold)
	 {
	   std::cout << "Sell History:" << std::endl;
	   for (int i = 0; i < soldCounter; i++)
	     {
	       std::cout << "Sold " << sellHistory[i].numShares << " shares at " << sellHistory[i].purchasePrice << std::endl;
	     }

	 }

}
