#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>


namespace fsu {

  //-----------CLASS QUEUE---------------//
  template < typename T>
  class Queue {

  private:
    char ofc_;

    //---------CLASS LINK----------//

    class Link
    {
      Link(const T& t) : element_(t), nextLink_(0) {}
      T element_;
      Link* nextLink_;
      friend class Queue<T>;
    };
    Link * firstLink_;
    Link * lastLink_;

  public:
    //QUEUE FUNCTIONS
    void Push(const T& t);
    T Pop();
    T& Front();
    const T& Front() const;
    size_t Size() const;
    bool Empty() const;
    void Clear();
    size_t Capacity() const;
    void Append(const Queue& q);
    void Release();

    //CONSTRUCTORS
    Queue();
    Queue(char ofc);
    Queue(const Queue&);
    ~Queue();
    Queue& operator = (const Queue&);

    //DISPLAY METHODS
    void Display(std::ostream& os) const;
    void SetOFC(char ofc);
    void Dump(std::ostream& os) const;
  };

  template<typename T>
  std::ostream& operator<< (std::ostream& os, const Queue<T>& q)
  {
    q.Display(os, '\0');
    return os;
  }
  
  template<typename T>
  Queue<T>::Queue() : firstLink_(0), lastLink_(0) {}

  template<typename T>
  Queue<T>::Queue(char ofc) : ofc_(ofc)
  {
  }

  template<typename T>
  Queue<T>::Queue(const Queue & queue) : firstLink_(0), lastLink_(0)
  {
    if (!queue.Empty())
    {
      Append(queue);
    } else
    {
      return;
    }
  }

  template<typename T>
  Queue<T>::~Queue() { Release(); }

  template<typename T>
  Queue<T>& Queue<T>::operator=(const Queue & queue)
  {
    if (&queue != this) {

      if (!queue.Empty())
      {
        Append(queue);
      }
    }
    return *this;
  }

  template<typename T>
  void Queue<T>::Push(const T& t)
  {
    Queue<T>::Link* tVal_ = new Link(t);

    if (!Empty()) {
      lastLink_->nextLink_ = tVal_;
      lastLink_ = tVal_;
    }
    else
    {
      lastLink_ = tVal_;
      firstLink_ = tVal_;
    }
  }

  template<typename T>
  void Queue<T>::Display(std::ostream& os) const
  {
    Queue<T>::Link* link = firstLink_;

    if (!Empty())
    {    
      if (ofc_ == '\0') {
        while (link != 0) {
          os << link->element_;
          link = link->nextLink_;
        }
        os << "\n";
        return;
      } else
      {
        while (link != 0)
        {
          os << link->element_ << ofc_;
          link = link->nextLink_;
        }
      }
    }
    else
    {
      return;
    }
  }

  template<typename T>
  void Queue<T>::SetOFC(char ofc)
  {
    ofc_ = ofc;
  }

  template<typename T>
  void Queue<T>::Dump(std::ostream & os) const
  {
    Display(os);
  }

  template <typename T>
  T Queue<T>::Pop()
  {
    Queue<T>::Link* linkTemp = firstLink_;
    
    if (!Empty()) {

    if(firstLink_ == lastLink_)
    {
      firstLink_ = 0;
      lastLink_ = 0;
    }
    else 
    {
      firstLink_ = firstLink_->nextLink_;
    }
      T qe_ = linkTemp->element_;
      delete linkTemp;
      return qe_;

    }
    else
    {
      std::cerr << "** Queue error: Pop called on empty queue" << "\n";
      //exit(EXIT_FAILURE);
    }
  }

  template<typename T>
  T & Queue<T>::Front()
  {
    Queue<T>::Link* current = firstLink_;

    if (!Empty())
    {
      return current->element_;
    } 
    else 
    {
      std::cerr << "** Queue error: Front called on empty queue\n";
      //exit(EXIT_FAILURE);
    }

    // return current->element_;
    
  }

  template<typename T>
  const T & Queue<T>::Front() const
  {
    Queue<T>::Link* current = firstLink_;

    if (!Empty())
    {
      return current->element_;
    } 
    else 
    {
      std::cerr << "** Queue error: Front called on empty queue\n";
      //exit(EXIT_FAILURE);
    }

    // return current->element_;

  }

  template<typename T>
  void Queue<T>::Clear()
  {
    // T qe_ = firstLink_->element_;
    /*
    if (Size() == 0) {
      std::cerr << "Clear called on an empty Queue";
    } 
    else {
      while (!Empty()) {

        firstLink_ = firstLink_->nextLink_;
      }
    }
    */

    Release();
  }

  template<typename T>
  size_t Queue<T>::Capacity() const
  {
    return Size();
  }

  template<typename T>
  void Queue<T>::Append(const Queue & queue)
  {
    Queue<T>::Link* link = queue.firstLink_;

    T element = link->element_;

    Queue<T>::Link* newlink_ = new Link(element);

    lastLink_ = newlink_;
    firstLink_ = newlink_;
    link = link->nextLink_;

    while (link != 0)
    {
      T element = link->element_;
      Queue<T>::Link* newLink_ = new Link(element);
      lastLink_->nextLink_ = newLink_;
      lastLink_ = newLink_;
      link = link->nextLink_;
    }
  }

  template<typename T>
  void Queue<T>::Release()
  {
    if (!Empty())
    {
      while (firstLink_ != 0)
      {
        firstLink_ = firstLink_->nextLink_;
      }
    }

    firstLink_ = 0;
    lastLink_ = 0;
  }


  template <typename T>
  bool Queue<T>::Empty() const
  {
    if (firstLink_ == 0)
    {
      return true;
    }
    else
    {
      return false;
    }

  }

  template<typename T>
  size_t Queue<T>::Size() const
  {
    size_t size = 0;
    if (!Empty()) {
      Queue<T>::Link* temp = firstLink_;

      while (temp != 0) {
        temp = temp->nextLink_;
        ++size;
      }
      return size;
    }
    else {
      return size;
    }
    return size;
  }


}
#endif // !TQUEUE_H
