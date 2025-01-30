#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

// Adds a value to the back of the list 
void ULListStr::push_back(const std::string& val)
{
  // CASE 1: List is empty, make a new item to fill 
  if (head_ == NULL && tail_ == NULL) 
  {
    head_ = new Item();
    tail_ = head_; 
    head_->val[0] = val;
    head_->first = 0; 
    head_->last = 1;
  }
  // CASE 2: There is space in an existing item to add a value at the back
  else if (tail_->last < ARRSIZE) 
  {
    tail_->val[tail_->last] = val; 
    tail_->last++;
  }
  // CASE 3: The tail is full, make a new item to fill and link 
  else 
  {
    // create new item and then insert values
    Item* newItem = new Item();
    newItem->val[0] = val; 
    // set the values for first and last to indicate where this val is
    newItem->first = 0;
    newItem->last = 1; 

    // link the item to the previous tail 
    newItem->prev = tail_;
    newItem->next = NULL; 
    tail_->next = newItem;
    tail_ = newItem; 
  }
  // Increment list size 
  size_++;
}

// Adds a value to the front of the list
  void ULListStr::push_front(const std::string& val) 
  {
    // CASE 1: List is empty, make a new item to fill 
    if (head_ == NULL && tail_ == NULL) 
    {
      head_ = new Item();
      tail_ = head_; 
      head_->val[0] = val;
      head_->first = 0; 
      head_->last = 1;
    }
    // CASE 2: There is space in existing head item to add a value to the front
    else if (head_->first > 0)
    {
      head_->first--;
      head_->val[head_->first] = val;
    }
    // CASE 3: The head is full, make a new item to fill and link
    else
    {
      Item* newItem = new Item();
      newItem->val[ARRSIZE-1] = val; 
      newItem->first = ARRSIZE - 1; 
      newItem->last = ARRSIZE;

      // link the item to the previous head item
      newItem->next = head_;
      head_->prev = newItem; 
      head_ = newItem; 
    }
    // Increment list size
    size_++;
  }

  // Removes a value from the back of the list
  // Assume the list is not empty
  void ULListStr::pop_back()
  {
    // remove the last value in the tail 
    tail_->last--; 

    // check if the tail becomes empty. if so, delete it
    if (tail_->first == tail_->last) 
    {
      Item* temp = tail_; 
      tail_ = tail_->prev; 
      if (tail_) {
        tail_->next = NULL;
      }
      else 
      {
        head_ = NULL;
      }
      delete temp; 
    }
    // decrement size
    size_--;
  }
  
  // Removes a value from the front of the list
  void ULListStr::pop_front()
  {
    // remove the first value, replace index with next value in list
    head_->first++;

    // check if the tail becomes empty. if so, delete it
    if (head_->first == head_->last) 
    {
      Item* temp = head_; 
      head_ = head_->next; 
      if (head_)
      {
        head_->prev = NULL;
      }
      else
      {
        tail_ = NULL;
      }
      delete temp;
    }
    // decrement size
    size_--;
  }

  // Returns a const reference to the back element
  std::string const & ULListStr::back() const 
  {
    return tail_->val[tail_->last - 1];
  }

  // Returns a const reference to the front element
  std::string const & ULListStr::front() const
  {
    return head_->val[head_->first];
  }

  // Returns a pointer to the i-th value in the entire list
  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    // if non-existent location is given, return NULL
    if (loc >= size_)
    {
      return NULL;
    }

    // search through the whole list to find desired location
    Item* currentItem = head_; 
    while (currentItem != NULL)
    {
      // make sure that loc is within the values 
      if (loc < (currentItem->last - currentItem->first))
      {
        return &(currentItem->val[currentItem->first + loc]);
      }
      // check the next item for desired loc
      loc = loc - (currentItem->last - currentItem->first);
      currentItem = currentItem->next; 

    }
    return NULL;
  }
