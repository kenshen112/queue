/***********************************************************************
* Header:
*    QUEUE
* Summary:
*    A custom Queue class. First in first out
* Author
*    Kenyon Bunker and Tim O'Barr
************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include <assert.h>

namespace custom {
template <class T> 
class queue {
private:
   T *data;
   int numPush;
   int numPop;
   int numCapacity;
   bool isEmpty;
   int numItems;
   bool isFull;

   //Private function prototypes
   void resize(int & tempFront);
   int iHead();
   int iTail();
   bool full();
public:
   //Constructors
   //Default Cosntructor
   queue();
   //Non-default cosntructor
   queue(int c);
   //Copy Constructor
   queue(const queue<T> &rhs);
   //Destructor
   ~queue();

   
 /********************************************
 * ASSIGNMENT OPERATOR
 *******************************************/
   queue<T> & operator=(queue<T> & rhs)
   {
      numPush = 0;
      numPop = 0;

      if (numCapacity < rhs.size())
      {
         resize(rhs.numCapacity);
      }

      for (int i = rhs.numPop; i < rhs.numPush; i++)
      {
         push(rhs.data[i % rhs.numCapacity]);
      }
      return *this;
   }
   //Function Prototypes
   T & front();
   T & back();
   int size();
   void push(const T &element);
   void clear();
   void pop();
   bool empty();
};

template <class T>
T& queue<T>::front()
{
	if (numCapacity == 0)
	{
		throw "ERROR: Unable to reference the element from an empty Queue";
	}

	else
	{
		return data[numPop];
	}
}

template <class T>
T& queue<T>::back()
{
	if (empty())
	{
		throw "ERROR: Unable to reference the element from an empty Queue";
	}

	else if (numPush == 0)
	{
		return data[numCapacity - 1];
	}

	else
	{
		return data[numPush - 1];
	}
}

template <class T>
void queue <T>::pop()
{
	if (numCapacity == 0)
	{
		throw "ERROR: Unable to pop from an empty Queue";
	}

	numCapacity--;
	numPop = (numPop + 1) % numCapacity;
}

/********************************************
 * CONSTRUCTOR: DEFAULT
 *******************************************/
template<class T>
queue<T>::queue()
{
   numPush = 0;
   numPop = 0;
   numCapacity = 0;
   data = new T[numCapacity];
   isEmpty = true;
   numItems = 0;
}

/********************************************
 * CONSTRUCTOR: NON-DEFAULT
 *******************************************/
template<class T>
queue<T>::queue(int c)
{
   numPush = 0;
   numPop = 0;
   numCapacity = c;
   data = new T[numCapacity];
   isEmpty = true;
   numItems = 0;
}

/********************************************
 * CONSTRUCTOR: COPY
 *******************************************/
template<class T>
queue<T>::queue(const queue<T>& rhs)
{
   assert(rhs.numCapacity >= 0);

   // do nothing if there is nothing to do
   if (rhs.numCapacity == 0)
   {
      numCapacity = 0;
      numItems = 0;
      numPush = 0;
      numPop = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   // copy over the capacity and size
   numCapacity = rhs.numCapacity;
   numItems = rhs.numItems;
   numPop = 0;
   numPush = numItems;

   int tempFront = rhs.numPop;
   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < rhs.numItems; i++, tempFront = (tempFront + 1) % numCapacity)
      data[i] = rhs.data[tempFront];
}

/********************************************
 * DESTRUCTOR
 *******************************************/
template<class T>
inline queue<T>::~queue()
{
   clear();
}


/********************************************
 * Queue : SIZE
 * gets the queue size
 *******************************************/
template<class T>
int queue<T>::size()
{
   return numPush - numPop;
}

/********************************************
 * Queue : RESIZE
 * resizes the queue buffer
 *******************************************/
 template<class T>
   void queue<T>::resize(int &tempFront)
   {
     T *temp = nullptr;
     //step 1: if maxCapacitry is 0 alloc to 1 change capacity done.
     //step 2: multiply cap by 2 to double make a new variable to conserve data.

     if (tempFront == 0) //step 1.
       {
	 tempFront = 1;
	 data = new T[tempFront];

	 return;
       }

     else if (numPush == tempFront) //step 2.
       {
	 tempFront = tempFront * 2;

	 temp = new T[tempFront];

	 int tempPush = numPush;

	 for (int i = 0; i < numPush; i++)
	   {
	     temp[i] = data[i];
	   }

	 delete[] data;
       }

     data = temp;

     return;
   }

/********************************************
 * Queue : iHead
 * keeps track of the beggining of the queue
 *******************************************/
template<class T>
int queue<T>::iHead()
{
   
   return numPop % numCapacity;
}

/********************************************
 * Queue : iTail
 * keeps track of the end of the queue
 *******************************************/
template<class T>
int queue<T>::iTail()
{  
   //(numPush++ % numCapacity;
   //return numPush;
   return (numPush - 1) % numCapacity;
}

template<class T>
bool queue<T>::full()
{
   if (numPush == iHead())
   {
      isFull = true;
   }
   else
   {
      isFull = false;
   }
      
   return isFull;
}

/********************************************
 * Queue : PUSH
 * Adds an element to the back of the queue
 *******************************************/
template<class T>
void queue<T>::push(const T & element)
{
	if (size() <= numCapacity) {
		resize(numCapacity);
		std::cout << "resize" << std::endl;
	}
	data[iTail()] = element;
	numPop = (numPop + 1) % numCapacity;
	numPush++;
}

/********************************************
 * queue : CLEAR
 * frees queue memory
 *******************************************/
template <class T>
void queue <T> ::clear()
{
   data = NULL; // This could error out try data = NULL;
   delete[] data;
   numPush = 0;
   numPop = 0;
   numCapacity = 0;
}
/********************************************
 * queue : EMPTY
 * Checks if queue is empty
 *******************************************/
 template<class T>
   bool queue<T>::empty(){ return size() == 0; }

}// namespace custom
#endif /* QUEUE_H */
