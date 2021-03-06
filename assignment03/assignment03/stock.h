/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    Holds variables for  stock data and functions for the pruchase
 *    and sale of stocks, and displays that data.
 * Author
 *    Tim O'Barr
 *    Kenyon Bunker
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;
using namespace custom;

/***********************************************
* Structure STOCKDATA
* holds stock data
***********************************************/
struct stockData
{
   Dollars profitLoss;        //used in display and calc as profit or loss for a sale
	Dollars purchasePrice;     //purchase price of stock
	Dollars sellPrice;         //selling price of stock
	int numShares;             //num of shares purchased/sold
	int totalShares;           //total shares. not sure if we need this
};

/***********************************************
* Main stock body
***********************************************/
class stock
{
private:   
   //variables
	queue <stockData> data;    //creates queue of stockData
	bool sold;
	int boughtCounter;
	int soldCounter;
   Dollars proceeds;          //running total
   vector <stockData> sellHistory;
public: 
   //Cosntructors
   stock();

   //Prototype functions
   void stocksBuySell();         // the interactive stock buy/sell function
   float calcProfitLoss();       // Calculates the profit and loss of purchased and sold stocks
   void display();               //Displays currently held, sell history, and proceeds of stocks
};
#endif // STOCK_H

