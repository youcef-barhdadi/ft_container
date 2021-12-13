
#include <iostream>
# include "../map/bidirectional_iterator.hpp"
#include "../map/reverse_bidirection_iterator.hpp"
#include "../map/rbtree.hpp"

namespace ft {

template < class T,                        // Set::key_type/value_type
		   class Compare = std::less<T>,        // Set::key_compare/value_compare
		   class Alloc = std::allocator<T>      // Set::allocator_type
		   > class Set
{
	public:

	typedef T                                   key_type;

	typedef T                                   value_type;

	typedef Compare                              value_compare;

	typedef Alloc                               allocator_type;

	typedef T&                                  reference;

	typedef const T&                            const_reference;

	typedef T*                                  pointer; 

	typedef const T*                         const_pointer; 

	typedef ft::bidirectional_iterator<ft::node<T> >           iterator;

	typedef ft::const_bidirectional_iterator<ft::node<T> >     const_iterator;

	typedef ft::reverse_iterator <iterator>          reverse_iterator;

	typedef ft::reverse_iterator <iterator>          const_reverse_iterator;

	typedef ptrdiff_t                           difference_type;

	typedef size_t                              size_type;

	typedef		Compare								key_compare;

	ft::RBtree<value_type> tree;



   iterator begin()
	{
	  return iterator(tree.findSamllest(this->tree.root), tree.root);
	}

	reverse_iterator rbegin()
	{
	  return reverse_iterator(this->end());
	}

	const_reverse_iterator rbegin() const
	{
	  return const_reverse_iterator(this->end());
	}

	reverse_iterator rend()
	{
	  return reverse_iterator(this->begin());
	}
	const_reverse_iterator rend() const
	{
	  return const_reverse_iterator(this->begin());
	}

	const_iterator begin() const
	{
	  return const_iterator(this->tree.findSamllest(tree.root), tree.root);
	}

	iterator end()
	{
	  return iterator(NULL, tree.root);
	}

	const_iterator end() const
	{
	  return const_iterator(NULL, tree.root);
	}


	bool empty() const
	{
		return (this->tree.size() == 0);
	}

	size_type size() const
	{
		return this->tree.size();
	}

	size_type max_size() const
	{
		// fix this
		return this->tree.my_alloc;
	}

	pair<iterator,bool> insert (const value_type& val)
	{
		node<value_type> *n = tree.find(val);
		if (n != NULL)
		{
			return ft::make_pair<iterator, bool>(iterator(n, tree.root), false);
		}
		else
		{
			tree.insert(val);
			n = tree.find(val);
			return ft::make_pair<iterator, bool>(iterator(n, tree.root), true);
		}
	}

	iterator insert (iterator position, const value_type& val)
	{
		this->insert(val);
		node<value_type> *n = tree.find(*position);
		return iterator(n, tree.root);
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
		{
		this->insert(*first);
		++first;
		}
	}

	void erase (iterator position)
	{
		tree.remove(*position);
	}

	size_type erase (const value_type& val)
	{
		return tree.remove(val);
	}

	void erase (iterator first, iterator last)
	{
	  while (first != last)
      {
        tree.remove(*first);
        ++first;
      }	
	}

	void swap (Set& x)
	{
	  node<value_type> *r1 = x.tree.root;
      size_t size1 = x.tree._size;

      x.tree.root = this->tree.root;
      this->tree.root = r1;

      x.tree._size = this->tree._size;
      this->tree._size = size1;
	}

	void clear()
	{
		erase(this->begin(), this->end());
	}

	key_compare key_comp() const
	{

	}

	value_compare value_comp() const
	{

	}

	iterator find (const value_type& val) const
	{

	}

	size_type count (const value_type& val) const
	{

	}

	iterator lower_bound (const value_type& val) const
	{

	}

	iterator upper_bound (const value_type& val) const
	{

	}

	pair<iterator,iterator> equal_range (const value_type& val) const
	{

	}

	allocator_type get_allocator() const
	{

	}




	














};


};