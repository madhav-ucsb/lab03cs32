#include <string>
#include "studentRoll.h"
#include <iostream>

StudentRoll::StudentRoll() {
  head = tail = NULL;

}

void StudentRoll::insertAtTail(const Student &s) {
  // STUB
  
  Node *p = new Node; // temporary pointer

  // TODO:
  // (1) Allocate a new node.  p will point to it.
 // THIS IS PLACE-HOLDER LINE OF CODE.  DELETE IT AND REPLACE IT.

  p->s = new Student(s.getName() , s.getPerm());

  std::cout<<p->s->getName()<<std::endl;
  (*p).next = nullptr;// (3) Set p's next field to NULL

  if (this->head == nullptr) {

    //std::cout<<"entering this part 1"<<std::endl;
    

    this->head = p;
    //std::cout<<"entering this part 2 "<<std::endl;

    this -> tail = p;// (4) Make both head and tail of this list point to p
    //std::cout<<"entering this part 3"<<std::endl;

    
    
    
  } 
  else {
    std::cout<<"entering else part"<<std::endl;
    this->tail->next = p;// Add p at the end of the list.   
    this->tail = this->tail->next;
    // (5) The current node at the tail? Make it point to p instead of NULL
    this->tail->next = NULL;
    return;
    //return;
    // (6) Make the tail of the list be p now.
}
  
  



}

std::string StudentRoll::toString() const {
  std::string s = "[";
  Node* temp = this->head;

  while(temp)
    {
      s = s + (*temp->s).toString();
    }
  return s + "]";
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB

  if(&orig == this)
  {
    return;
  }
  Node* temp = orig.head;

  while(temp->next)
  {
    (*this).insertAtTail(*temp->s);
      
  }

  
  
}

StudentRoll::~StudentRoll() {


    Node *h = this->head;

    Node *temp = h;

    while(h)
    {
      temp = h->next;

      

      delete h;

      h = temp;
    }

}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  this->head = nullptr;
  this->tail = nullptr;

  Node* temp = right.head;

  while(temp->next)
  {
    (*this).insertAtTail(*temp->s);
      
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}




