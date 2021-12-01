#include <iostream>



	template <typename T>
	class node
	{


		public:
		node(const T &e) : data(e),
			                   next(0), prev(0)
		{ }

		T data;
		node<T> *next;
		node<T> *prev;
	};

template <class T>
class iteratorList 
{
    private:
        node<T> *_p;
    public:
        iteratorList				&operator++(void)
        {
            _p = _p->next;
        }

        iteratorList				&operator--(void)
        {
            _p = _p->prev;
        }
};

