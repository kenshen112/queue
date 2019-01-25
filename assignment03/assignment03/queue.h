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
}

/********************************************
 * CONSTRUCTOR: COPY
 *******************************************/
template<class T>
queue<T>::queue(const queue<T>& rhs)
{
   //TODO: KENYON: rework this for queue
   try
   {
      if (numElements != rhs.numElements) {
         data = new T[rhs.numElements];
      }

      for (int i = 0; i < rhs.size(); i++) {
         data[i] = rhs.data[i];
      }

      numCapacity = rhs.numCapacity;
      numElements = rhs.numElements;
   }
   catch (std::bad_alloc &er) {
      throw(" ERROR: Unable to allocate a new buffer for queue");
      exit(1);
   }
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