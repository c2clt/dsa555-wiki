// array implementaion of Queue
template <typename T>
class Queue{
  T* theQueue_;
  int used_;
  int capacity_;
  int front_;    // index of the first item in queue
  int back_;     // index of where new element will be added to the queue
                 // is is one element "after" end of the queue
  void grow(){
    T* tmp = new T[capacity_ * 2];
    int j = front_;
    for(int i = 0; i < used_; i++){
      tmp[i] = theQueue_[j];
      j = (j + 1) % capacity_;
    }
    delete [] theQueue_;
    theQueue_ = tmp;
    capacity_ = 2 * capacity_;
    front_ = 0;
    back_ = used_;
  }

public:
  Queue(int capacity = 4){
    capacity_ = capacity;
    theQueue_ = new T[capacity_];
    used_ = 0;
    front_ = 0;
    back_ = 0;
  }
  
  void enqueue(const T& data){
    if(used_ == capacity_){
      grow();
    }
    theQueue_[back_] = data;
    if(back_ + 1 == capacity_){
      back_ = 0;
    }
    else{
      back_++;
    }
    
    used_++;
  }
  
  void dequeue(){
    if(used_ > 0){
      used_--;
      front_ = (front_ + 1) % capacity_;
    }
  }
  
  const T& front() const{
    if(used_){
      return theQueue_[front_];
    }
  }
  
  bool isEmpty(){
    return used_ == 0;
  }
  
  ~Queue(){
    delete[] theQueue_;
    theQueue_ = nullptr;
  }
}
