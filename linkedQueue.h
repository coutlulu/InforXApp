#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node
template <class Type>
struct nodeTypeQ
{
    Type info;
    nodeTypeQ<Type> *link;
};


template <class Type>
class linkedQueueType
{
public:
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&); 
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty. 
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full. 
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = NULL; queueRear = NULL

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the first 
      //               element of the queue is returned. 

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the last 
      //               element of the queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first 
      //               element is removed from the queue.

    linkedQueueType(); 
      //Default constructor

    linkedQueueType(const linkedQueueType<Type>& otherQueue); 
      //Copy constructor

    ~linkedQueueType(); 
      //Destructor

private:
    nodeTypeQ<Type> *queueFront; //pointer to the front of 
                                //the queue
    nodeTypeQ<Type> *queueRear;  //pointer to the rear of 
                                //the queue
   void copyQueue(const linkedQueueType<Type>& otherQueue); 
    
};

    //Default constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType() 
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end 

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeTypeQ<Type> *temp;

    while (queueFront!= NULL)  //while there are elements left
                               //in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->link;  //advance first to  
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeTypeQ<Type> *newNode;

    newNode = new nodeTypeQ<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL

    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear=newNode; 
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info; 
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeTypeQ<Type> *temp;
   
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the 
                            //first node
        queueFront = queueFront->link; //advance queueFront 

        delete temp;    //delete the first node

        if (queueFront == NULL) //if after deletion the 
                                //queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


    //Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() 
{
    //Write the definition of the destructor
} //end destructor

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                    (const linkedQueueType<Type>& otherQueue)
{
    //Write the definition of to overload the assignment operator
     if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);

    return *this; 
   
} //end assignment operator


//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
                 (const linkedQueueType<Type>& otherQueue) 
{
    //Write the definition 
    queueFront = NULL;
    copyQueue(otherQueue);
}//end copy constructor

template <class Type> 
void linkedQueueType<Type>::copyQueue
                     (const linkedQueueType<Type>& otherQueue)
{
    nodeTypeQ<Type> *newNode, *current, *last;

    if (queueFront != NULL) //if stack is nonempty, make it empty
        initializeQueue();

    if (otherQueue.queueFront == NULL)
        queueFront = NULL;
    else
    {
        current = otherQueue.queueFront;  //set current to point to the queue to be copied

        //copy the queuefront element of the Queue 
        queueFront = new nodeTypeQ<Type>;  //create the node
        queueFront->info = current->info; //copy the info
        queueFront->link = NULL;  //set the link field of the node to NULL
        //last = queueFront;        //set last to point to the node
        queueRear = queueFront;   
        current = current->link;    //set current to point to the next node

        //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeTypeQ<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            queueRear->link = newNode;
            queueRear = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyQueue

