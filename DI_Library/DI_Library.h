#pragma once

template<class TYPE>
class Singleton;  

template<class TYPE, class HASH>
struct Link
{
    TYPE* ptr_to_func;
    Link* next;
};

template<class TYPE>
class SingletonDestroyer
{
private:
    TYPE* p_instance;
public:
    ~SingletonDestroyer();
    void initialize(TYPE* p);
};

template<class TYPE>
class Singleton
{
private:
    friend class TYPE;
    static TYPE* p_instance;
    static SingletonDestroyer<TYPE> destroyer;
protected:
    Singleton() { }
    ~Singleton() { }
    friend class SingletonDestroyer<TYPE>;
public:
    static TYPE& getInstance();
};


template<class TYPE,class HASH>
class Transient
{
private:
    link <TYPE,HASH>* first;
public:
    Transient();
    HASH add_link();
};
