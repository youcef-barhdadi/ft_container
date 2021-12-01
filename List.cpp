#include <list>
#include <iostream>
#include <iterator>
#include <memory>




	template <typename T>
	class node
	{


		public:
		node(const T &e) : data(e),
			                   next(0), prev(0)
		{ }
		node(){}

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
			return *this;
        }

        iteratorList				&operator--(void)
        {
            _p = _p->prev;
			return *this;
        }
		iteratorList(node<T> *n)
		{
			_p =n;
		}

		void print()
		{
			std::cout << _p->data << std::endl;
		}


		T &operator*()
		{
			return this->_p->data;
		}




		
		node<T> *getnode()
		{
			return _p;
		}



};










template< class T, class A = std::allocator<T>> class list
{

	private:
		typedef T value_type;
		typedef A allocator_type;
		typedef typename A::reference				reference;
		typedef typename A::const_reference			const_reference;
		typedef typename A::pointer					pointer;
		typedef typename A::const_pointer			const_pointer;
		typedef typename A::difference_type			difference_type;
		typedef typename A::size_type				size_type;

		node<T> *head;
		node<T> *tail;
		size_t _size;

	public:
			typedef iteratorList<T>				 iterator;

	list()
	{
	//	this->size_type = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
	list( const list& other )
	{
	// 	this->allocator_type = other.allocator_type;
	// 	this->size_type = other.size_type;
	// 	this->value_type = other.value_type;
	// 	this->difference_type = other.difference_type;
	}








	// method


	size_t size()
	{
		return this->_size;
	}
	void clear()
	{
		node<T> *temp;
		node<T> *tofree;

		temp = this->head;

		while (temp != nullptr)
		{
			tofree = temp;
			temp = temp->next;	
			delete  tofree;
		}
		this->_size = 0;
	}

	void insertInternal(iteratorList<T> position , const value_type& val)
	{
	

	}



	iterator insert (iteratorList<T> position, const value_type& val)
	{
		node<T>  *n;
		n = position.getnode();
		node<T> *next;
		next = n->next;
		n->next = new node<T>(val);
		n->next->next= next; 
		++position;
		return position;
	}


	T &front()
	{
		 return head->data; 
	}


	T &back()
	{
		return tail->data; 
	}	

	iteratorList<T> begin()
	{
		return  iteratorList<T>(this->head);
	}

	void	push_back(const T &value)
	{
		this->_size++;
		if (this->head == nullptr)
		{
			this->head = new node<T>(value);
			this->tail = this->head;
			return ;
		}
		this->tail->next = new node<T>(value);
		this->tail = this->tail->next;
	}
};

 
int main()
{

	list<int> li;
	list<std::string> s;

	s.push_back("asf");
	 li.push_back(1337);
	 li.push_back(4);
	 li.push_back(5);
	 li.push_back(8);
	 li.push_back(5);


	list<int>::iterator it = li.begin();
	 list<int>::iterator l =  li.insert(it, 235);
	
std::cout << *l << std::endl;
	// int i = 0;
	// while (i < 4)
	// {
	// 	
	// 	++it;
	// 	i++;
	// }



}



