/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM
#include <vector>
#include <string>
#include <string.h>
#include <sstream>  
using namespace std;
using namespace custom;
struct stockData
{

	Dollars proceeds;          //running total
   Dollars profitLoss;        //used in display and calc as profit or loss for a sale
	Dollars purchasePrice;     //purchase price of stock
	Dollars sellPrice;         //selling price of stock
	int numShares;             //num of shares purchased/sold
	int totalShares;           //total shares. not sure if we need this
};


class stock
{
private:   
   //variables
	queue <stockData> data;

public:
   
   stock();
   // the interactive stock buy/sell function
  
   void stocksBuySell();
   vector <string> split(string s, char delimiter);
   float calcProfitLoss();
   void display();

};


#endif // STOCK_H

