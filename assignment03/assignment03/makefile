###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother Kirby, CS235
# Authors:
#     Kenyon Bunker
#     Tim O'Barr
# Summary:
#     Example of a queue and a stock class to buy and 
#     sell stocks
# Time:
#     Tim: 3
#     Kenyon: 3
#     Together: 10
# What was difficult?:
#     Kenyon: stock program. trying to figure out the best way
#       to get the input
#     Tim: stock program. trying to figure out the best way
#       to get the input
#     Both: Had issue with displaying Dollars in testBed. It
#       would display fine in VS and on Tims linux system
#       but not in testbed. You'll notice that in Current 
#       history the dollar amout shows 0 but in VS and linux
#       it does not. Any ideas?
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h assignment03.o dollars.o stock.o
	g++ -o a.out assignment03.o dollars.o stock.o -std=c++11
	tar -cf assignment03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      assignment03.o : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
assignment03.o: queue.h assignment03.cpp
	g++ -c assignment03.cpp -std=c++11

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp -std=c++11

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp -std=c++11
