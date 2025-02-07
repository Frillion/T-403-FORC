#include "personal_vector.h"

PersonalVector::PersonalVector(int size){
    capacity = size;
    this->size = 0;
    arr = new int[size];
}


PersonalVector::~PersonalVector(){
    delete[] arr;
}

bool PersonalVector::is_empty(){return size == 0;}

void PersonalVector::resize(){
    if(size == capacity){
        capacity *= 2;
        int *new_arr = new int[capacity];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    if(size <= capacity/4){
        capacity /= 2;
        int *new_arr = new int[capacity];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
}

int PersonalVector::erase(int index = -1){
    if(index >= size){return -1;}
    if(index < -1){return -1;}

    if(index == -1 || index == size - 1){
        int ret = this->pop_back();
        return ret;
    }

    size--;
    resize();
    int ret = arr[index];
    for(int i = index; i < size; i++){
        arr[i] = arr[i + 1];
    }
    return ret;
}

int PersonalVector::pop_back(){
    size--;
    resize();
    int ret = arr[size - 1];
    return ret;
}

void PersonalVector::insert(int index, int item){
    size++;
    resize();
    for(int i = size; i > index; i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = item;
}

void PersonalVector::push_back(int item){
    size++;
    resize();
    arr[size] = item;
}

void PersonalVector::clear(){
    size = 0;
    resize();
}

int PersonalVector::operator[](int index){
    if(index >= size){return -1;}
    if(index < 0){return -1;}
    return arr[index];
};
