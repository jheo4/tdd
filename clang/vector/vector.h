/*
 *  Writer: Jin Heo
 *  Desc: practice clang TDD with catch2 and vector class
 *  Notice: because of Template, all codes are written in this header;
 *    there is no way to know the type while compling & linking process without
 *    explicit declaration. There are two solutions below.
 *      - Explicitly instantiate the template, and its member definitions
 *      - Copy the code into the relevant header file
 */
#define MIN_VEC_SIZE 0
#define MAX_VEC_SIZE 100
#include <iostream>

template <class T>
class Vector{
  private:
    T *element_pointer;
    int capacity;
    int size;
  public:
    Vector(int init_elements = MIN_VEC_SIZE){
      if(init_elements < MIN_VEC_SIZE || init_elements > MAX_VEC_SIZE){
        throw std::logic_error("init vector out of range");
        init_elements = MIN_VEC_SIZE;
      }
      element_pointer = new T[init_elements];
      size = init_elements;
      capacity = init_elements;
    }


    ~Vector(){
      if(element_pointer != NULL){
        delete []element_pointer;
      }
    }


    int get_size(){return size;}
    int get_capacity(){return capacity;}
    T* get_elements(){return element_pointer;}


    T get_element(int index){
       if(index >= size || index < MIN_VEC_SIZE){
        throw std::logic_error("invalid index");
        return false;
      }
      return element_pointer[index];
    }


    void print_elements(){
      std::cout << "(size/capacity): (" << size << "/" << capacity << ")"
        << std::endl;
      for(int i = 0; i < capacity; i++){
        std::cout << i << "th elements: " << element_pointer[i] << std::endl;
      }
    }


    bool resize(int input_size){
      if(input_size > MAX_VEC_SIZE || input_size < MIN_VEC_SIZE){
        throw std::logic_error("input size out of range");
        return false;
      }

      if(input_size > size){
        T *temp_elements =
          Vector::get_copied_elements(element_pointer, size, input_size+1);
        delete []element_pointer;
        element_pointer = temp_elements;

        size = input_size;
        if(input_size > capacity)
          capacity = input_size;
      }
      else{
        size = input_size;
        return true;
      }
      return false;
    }


    bool reserve(int input_capacity){
      if(input_capacity > MAX_VEC_SIZE || input_capacity < MIN_VEC_SIZE){
        throw std::logic_error("input capacity out of range");
        return false;
      }

      int num_elements = 0;

      if(input_capacity == capacity){
        return true;
      }
      else if(input_capacity <= size){
        num_elements = size;
      }
      else if(input_capacity != capacity){
        num_elements = input_capacity;
      }

      T *temp_elements = Vector::get_copied_elements(element_pointer,
          size, num_elements+1);

      delete []element_pointer;
      element_pointer = temp_elements;
      capacity = num_elements;
      return true;
    }


    bool push_back(T element){
      if(size == MAX_VEC_SIZE){
        throw std::logic_error("this vector is full");
        return false;
      }

      if(size == capacity){
        capacity = size+1;
        T* temp_elements =
          Vector<T>::get_copied_elements(element_pointer, size, capacity);

        delete []element_pointer;
        element_pointer = temp_elements;
      }
      element_pointer[size++] = element;
      element_pointer[size] = (T)NULL;
      return true;
    }


    T pop_back(){
      if(size == 0){
        throw std::logic_error("this vector is empty");
        return false;
      }

      T ret_value = element_pointer[size-1];
      element_pointer[size-1] = (T)NULL;
      return ret_value;
    }


    bool insert(T element, int index){
      if(index > capacity || index < MIN_VEC_SIZE){
        throw std::logic_error("index is out of range");
        return false;
      }

      if(index == size == capacity){
        return push_back(element);
      }
      if(index <= size){
        if(size == capacity)
          reserve(capacity+1);

        for(int i = size; i > index; i--){
          element_pointer[i] = element_pointer[i-1];
        }
        element_pointer[index] = element;
        size++;
        return true;
      }
      else
        return false;
    }


    T erase(int index){
      if(index >= capacity || index < 0){
        throw std::logic_error("index is out of range");
        return false;
      }

      T ret_value = element_pointer[index];
      for(int i = index; i < size; i++){
        element_pointer[i] = element_pointer[i+1];
      }
      size--;
      return ret_value;
    }


    bool clear(){
      for(int i = MIN_VEC_SIZE; i < capacity; i++){
        element_pointer[i] = (T)NULL;
      }
      size = 0;
      return true;
    }


    bool swap_elements(int index1, int index2){
      return false;
    }


    bool reverse(Vector original_vector, Vector reversed_vecotr){
      return false;
    }


    static T* get_copied_elements(T *original,
        int original_size, int target_size){
      T *temp_elements = new T[target_size+1];
      int num_elements =
        (original_size >= target_size ? target_size : original_size);

      for(int i = 0 ; i < target_size+1; i++){
        if(i < num_elements)
          temp_elements[i] = original[i];
        else
          temp_elements[i] = (T)NULL;
      }

      return temp_elements;
    }
};
