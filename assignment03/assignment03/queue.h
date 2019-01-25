#pragma once
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
namespace custom {
template <class T> class queue {
private:
   T *data;
   int numPush;
   int numPop;
   int numCapacity;
   bool isEmpty;
   int numItems;

   //Private function prototypes
   int resize();
   int iHead();
   int iTail();
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

   //Function Prototypes
   T & operator = (const queue <T> & rhs);
   int size();
   void push(const T &element);
   void clear();
   bool empty();
};

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

   int tempFront = rhs.myFront;
   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < rhs.numItems; i++, tempFront = (tempFront + 1) % maxCapacity)
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
 * ASSIGNMENT OPERATOR
 *******************************************/
template<class T>
T & queue<T>::operator=(const queue<T> & rhs)
{
   numPush = 0;
   numPop = 0;

   if (numCapacity < rhs.size())
   {
      resize(rhs.size());
   }

   for (int i = rhs.numPop; i < rhs.numPush; i++)
   {
      push(rhs.data[i % rhs.numCapacity]);
   }
   return *this;
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
int queue<T>::resize()
{
   //Stub
   return 0;
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
   return (numPush - 1) % numCapacity;
}

/********************************************
 * Queue : PUSH
 * Adds an element to the back of the queue
 *******************************************/
template<class T>
void queue<T>::push(const T & element)
{
   //Stub
}

/********************************************
 * queue : CLEAR
 * frees queue memory
 *******************************************/
template <class T>
void queue <T> ::clear()
{
   data = nullptr;
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
 bool queue<T>::empty()
{
    if (size() == 0) {
       isEmpty = true;
    }
    else {
       isEmpty = false;
    }
    return isEmpty;
}


}// namespace custom
#endif /* STACK_H */