#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>

namespace fsu {
  template < typename T, size_t N = 100>
  class Stack {

  public:
    void Push(const T& t); //push data
    T Pop(); //pop data
    T& Top(); // copy constructor
    const T& Top() const; //copy constructor
    size_t Size() const; // size of size_
    size_t Capacity() const; //size of N
    bool Empty() const; //bool check to see if data_ is empty
    void Clear(); //clear entries

    Stack(); //default constructor
    Stack(char ofc, int dir); //argument constructor
    Stack(const Stack&); //object constructor
    ~Stack(); //destructor
    Stack& operator = (const Stack&); // assignment operator

    void Display(std::ostream& os) const; //Display data based on ofc_ and dir_
    void SetOFC(char ofc); //setter for ofc_
    void SetDIR(int dir); //setter for dir_
    void Dump(std::ostream& os) const; //programming dump of the array of data_


  private:
    const size_t capacity_;
    T data_[N];
    size_t size_;
    char ofc_;
    int dir_;
  };
  
  template < typename T, size_t N >
  std::ostream& operator << (std::ostream& os, const Stack<T, N>& s)
  {
    s.Display(os);
    return os;
  }

  template <typename T, size_t N>
  Stack<T, N>& Stack<T, N>::operator= (const Stack& rStack) {
    if (&rStack != this) {
      size_ = rStack.size_;
      for (size_t i = 0; i < N; ++i) {
        data_[i] = rStack.data_[i];
      }
      return *this;
    }
    return *this;
  }

  template<typename T, size_t N>
  size_t Stack<T, N>::Size() const
  {
    return size_;
  }

  template<typename T, size_t N>
  inline size_t Stack<T, N>::Capacity() const
  {
    return N;
  }

  template<typename T, size_t N>
  bool Stack<T, N>::Empty() const
  {
    if (size_ != 0) {
      return false;
    }
    return true;
  }


  template <typename T, size_t N>
  fsu::Stack<T, N>::Stack() : capacity_(N), data_(), size_(0) {}

  template <typename T, size_t N>
  fsu::Stack<T, N>::Stack(const Stack& copy) : capacity_(copy.capacity_), data_(), size_(copy.size_)
  {
    for (size_t i = 0; i < N; ++i) {
      data_[i] = copy.data_[i];
    }
  }

  template <typename T, size_t N>
  fsu::Stack<T, N>::Stack(char ofc, int dir) : capacity_(N), data_(), size_(0), ofc_(ofc), dir_(dir)
  {}

  template<typename T, size_t N>
  void fsu::Stack<T, N>::Display(std::ostream & os) const
  {
    if (!Empty()) {
      if (dir_ == 1) {
        size_t i = 0;
        os << ofc_;
        for (; i < (size_ - 1); ++i) {
          os << data_[i];
          os << ofc_;
        }
        os << data_[size_ - 1];
        return;
      }
      else if (dir_ == -1) {
        size_t i = size_;
        while (i > 0)
        {
          i--;
          os << ofc_;
          os << data_[i];
        }
        //os << data_[size_];
        return;
      }
    }
    for (size_t i = 0; i < size_ - 1; ++i)
    {
      os << data_[i];
      os << " ";
    }
    os << data_[size_ - 1];
    return;
  }
  
  template<typename T, size_t N>
  void Stack<T, N>::SetOFC(char ofc)
  {
    ofc_ = ofc;
  }
  template<typename T, size_t N>
  void Stack<T, N>::SetDIR(int dir)
  {
    dir_ = dir;
  }

  template<typename T, size_t N>
  void Stack<T, N>::Dump(std::ostream & os) const
  {
    os << "Stack Dump(): " << '\n';
    os << "Capacity: " << N << '\n';
    os << "Size:     " << size_ << '\n';
    os << "Array:    " << "[";
    for (size_t i = 0; i < N; ++i) {
      os << data_[i];
      if (i < N - 1) 
        os << ",";
    }
    os << "]\n";
    os << "Stack:    " << "[";
    for (size_t i = 0; i < size_; ++i) {
      os << data_[i];
      if (i < size_ - 1) 
        os << ",";
    }
    os << "]\n";
  }

  template<typename T, size_t N>
  void fsu::Stack<T, N>::Push(const T & t)
  {
    if (size_ == capacity_)
    {
      std::cerr << "** Stack error: Push(" << t << ") called on full stack\n";
    }

    if (size_ < N)
    {
      data_[size_] = t;
      ++size_;
    }
  }

  template<typename T, size_t N>
  T fsu::Stack<T, N>::Pop()
  {
    T element;

    element = data_[size_];
    --size_;

    return element;

  }

  template<typename T, size_t N>
  T & Stack<T, N>::Top()
  {
    if (size_ > 0)
      return data_[size_ - 1];
    else 
      return data_[size_];
  }

  template<typename T, size_t N>
  const T & Stack<T, N>::Top() const
  {
    if (size_ > 0)
      return data_[size_ - 1];
    return data_[size_];
  }

  template<typename T, size_t N>
  void Stack<T, N>::Clear()
  {
    size_ = 0;
  }


  template <typename T, size_t N>
  fsu::Stack<T, N>::~Stack() {
    Stack::Clear();
    SetOFC('\0');
    SetDIR(0);
    //    delete data_;
  }
}
#endif // !TSTACK_H
