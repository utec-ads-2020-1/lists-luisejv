#include <iostream>
#include <string>
#include "linked.h"
#include "forward.h"
#include "circular.h"
#include "iterators/bidirectional_iterator.h"
#include "iterators/forward_iterator.h"

using namespace std;

int main() {
    LinkedList<int> linkedList;

    linkedList.push_back(5);
    linkedList.push_back(6);
    linkedList.push_front(7);
    linkedList.push_front(10);
    //cout << linkedList.size() << endl;
    for(int i = 0; i < linkedList.size(); i++){
        cout << linkedList[i] << " ";
    };
    cout << endl;

    cout << "Printing front element: ";
    cout << linkedList.front() << endl;
    cout << "Printing back element: " << linkedList.back() << endl;
    cout << "Poping an element in the front." << endl;
    linkedList.pop_front();
    cout << "Printing new front element: ";
    cout << linkedList.front() << endl;
    cout << "Poping an element in the back." << endl;
    linkedList.pop_back();
    cout << "Printing new back element: ";
    cout << linkedList.back() << endl;
    cout << "Pushing back elements again." << endl;
    linkedList.push_back(6);
    linkedList.push_front(8);

    cout << "Size: " << linkedList.size() << endl;

    cout << "Accessing fourth position in the list: " << linkedList[3] << endl;

    cout << "Is list empty? " << linkedList.empty() << endl;

    cout << "The size of the list is: " << linkedList.size() << endl;

    for(int i = 0; i < linkedList.size(); i++){
        cout << linkedList[i] << " ";
    };
    cout << endl;

    cout << "-----Sorting list-----" << endl;
    linkedList.sort();
    //print(linkedList);
    for(int i = 0; i < linkedList.size(); i++){
        cout << linkedList[i] << " ";
    };
    cout << endl;

    cout << "-----Reversing list-----" << endl;
    linkedList.reverse();
    for(int i = 0; i < linkedList.size(); i++){
        cout << linkedList[i] << " ";
    };
    cout << endl;

    cout << "-----Second List-----" << endl;
    LinkedList<int> secondLinked;
    secondLinked.push_back(12);
    secondLinked.push_back(31);
    secondLinked.push_back(24);
    secondLinked.push_front(158);
    for(int i = 0; i < secondLinked.size(); i++){
        cout << secondLinked[i] << " ";
    };
    cout << endl;

    cout << "-----Mergin lists-----" << endl;
    linkedList.merge(secondLinked);
    cout << linkedList.size() << endl;
    for(int i = 0; i < linkedList.size(); i++){
        cout << linkedList[i] << " ";
    };
    cout << endl;

    cout << "Last element in the merged list is: " << linkedList[linkedList.size()-1] << endl;
    cout << "First element in the merged list is: " << linkedList[0] << endl;
    cout << "Size of the merged list is: " << linkedList.size() << endl;
    cout << "The new tail has this element: " << linkedList.back() << endl;
    cout << "The new head has this element: " << linkedList.front() << endl;


    cout <<"Trying iterators. " << endl;
    BidirectionalIterator<int> it = linkedList.begin();
    cout << "The list begins with: " << *it << endl;
    ++it;
    cout << "Moving pointer forward: " << *it << endl;
    --it;
    cout << "Moing pointer backward: " << *it << endl;

    cout << "Are it and linked.begin() different? ";
    cout << (it != linkedList.begin()) << endl;

    return 0;
}
