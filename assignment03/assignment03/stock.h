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

struct stockData
{
	std::string input;
	float profitLoss;
	Dollars money;
	float purchasePrice;
	float sellPrice;
	int numShares;
	int amount;
};


class stock
{
private:   
   //variables
	queue <stockData> data;

public:
   // the interactive stock buy/sell function
   void stocksBuySell();
   float calcProfitLoss();
   void display();
};


#endif // STOCK_H

