#ifndef PERSONAL_VEC
#define  PERSONAL_VEC

class PersonalVector{
    private:
        int capacity;
        int size;
        int *arr;

        void resize(){
            if(size == capacity){
                capacity *= 2;
                int *old_arr = arr;
                arr = new int[capacity];
                for(int i = 0; i < size; i++){
                    arr[i] = old_arr[i];
                }
                delete[] old_arr;
            }
            if(size <= capacity/4){
                capacity /= 2;
                int *old_arr = arr;
                arr = new int[capacity];
                for(int i = 0; i < size; i++){
                    arr[i] = old_arr[i];
                }
                delete[] old_arr;
            }
        }


    public: 
        bool is_empty(){return size == 0;}
        int erase(int index = -1){
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

        int pop_back(){
            size--;
            resize();
            int ret = arr[size - 1];
            return ret;
        }

        void insert(int index, int item){
            size++;
            resize();
            for(int i = size; i > index; i--){
                arr[i] = arr[i - 1];
            }
            arr[index] = item;
        }

        void push_back(int item){
            size++;
            resize();
            arr[size] = item;
        }

        void clear(){
            size = 0;
            resize();
        }

    PersonalVector(int size){
        capacity = size;
        this->size = 0;
        arr = new int[size];
    }

    ~PersonalVector(){
        delete[] arr;
    }

    int operator[](int index){
        if(index >= size){return -1;}
        if(index < 0){return -1;}
        return arr[index];
    };
};

#endif // PERSONAL_VEC
