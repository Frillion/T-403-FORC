#ifndef PERSONAL_VEC
#define  PERSONAL_VEC

class PersonalVector{
    private:
        int capacity;
        int size;
        int *arr;
        void resize();

    public: 
        PersonalVector(int size);
        ~PersonalVector();
        bool is_empty();
        int erase(int index);
        int pop_back();
        void insert(int index, int item);
        void push_back(int item);
        void clear();
        int operator[](int index);
};

#endif // PERSONAL_VEC
