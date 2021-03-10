#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    //make new temp node nn  with key data
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue
    cout << "Inserting " << key << '\n';
    // if queue is empty, both the front and end should be nn
    if (isEmpty()) {
        queueFront = queueEnd = nn;
        return;
    }
    // if set node after queue end to nn, and set nn as the queue end
    else {
        queueEnd->next = nn;
	    queueEnd = nn;
        return;
    }
}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
        cout << "Removing " << queueFront->key << '\n';
        // create temp node for removing data
        Node *nn = queueFront;
        queueFront = queueFront->next;

        // if the front queue is empty, set the end to null, making
        // the whole queue empty
        if (queueFront == NULL) {
            queueEnd = NULL;
        }
        // remove temp node data
	    delete(nn);
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
