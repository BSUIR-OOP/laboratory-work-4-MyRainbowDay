#include "DI_Library.h"

template<class TYPE>
TYPE* Singleton<TYPE>::p_instance = 0;

template<class TYPE>
SingletonDestroyer<TYPE> Singleton<TYPE>::destroyer;

template<class TYPE>
SingletonDestroyer<TYPE>::~SingletonDestroyer() {
    delete p_instance;
}

template<class TYPE>
void SingletonDestroyer<TYPE>::initialize(TYPE* p) {
    p_instance = p;
}

template<class TYPE>
TYPE& Singleton<TYPE>::getInstance() {
    if (!p_instance) {
        p_instance = new TYPE();
        destroyer.initialize(p_instance);
    }
    return *p_instance;
}

template<class TYPE>
Transient<TYPE>::Transient()
{
    first = NULL;
}

template<class TYPE>
void Transient<TYPE>::add_link()
{
    link<TYPE>* newlink = new link<TYPE>;
    newlink->ptr_to_func = new TYPE();
    newlink->next = first;
    first = newlink;
}
