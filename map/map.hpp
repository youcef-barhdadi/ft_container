
#include "rbtree.hpp"
#include "pair.hpp"
#include "bidirectional_iterator.hpp"
#include "reverse_bidirection_iterator.hpp"
#include <iostream>
#include <ctime> // used to work with date and time


namespace ft
{

	// #define map 1



	template <
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<pair< const Key, T> > >
	class map
	{

	public:
		typedef T mapped_type;

		typedef pair<Key, T> value_type;

		typedef Key key_type;
		//  typedef Allocator allocator_type  ;

		typedef size_t size_type;

		typedef T &reference;

		typedef const T &const_refernce;

		typedef T *pointer;

		typedef const T *const_pointer;

		typedef ft::bidirectional_iterator<node<ft::pair<Key, T> > > iterator;

		typedef ft::const_bidirectional_iterator<node<ft::pair<Key, T> > > const_iterator;


		typedef ft::reverse_iterator<iterator> const_reverse_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;

		typedef Allocator allocator_type;

		typedef Compare key_compare;


		


		class value_compare
		{
			friend class map;

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};




		explicit map(const key_compare &comp = key_compare(),
								 const allocator_type &alloc = allocator_type()) : my_alloc(alloc) , _compare(comp)
		{
		}

		~map()
		{
		}



		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
		{
			this->_compare = comp;
			this->my_alloc = alloc;
			while (first != last)
			{
				this->insert(*first);
				++first;
			}
		}
		

		map(const map &x)
		{
			const_iterator c = x.begin();
			size_t size = x.size();

			while (size)
			{
				this->insert(*c);
				++c;
				size--;
			}
		}

		pair<iterator, bool> insert(const value_type &val)
		{
			node<value_type> *n = tree.find(val);
			if (n != NULL)
			{
				return ft::make_pair<iterator, bool>(iterator(n, &tree.root), false);
			}
			else
			{
				tree.insert(val);
				n = tree.find(val);
				return ft::make_pair<iterator, bool>(iterator(n, &tree.root), true);
			}
		}

		/*
							coorect this function
						*/

		iterator insert(iterator position, const value_type &val)
		{
			this->insert(val);
			node<value_type> *n = tree.find(*position);
			return iterator(n, tree.root);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->insert(*first);
				++first;
			}
		}


		bool empty() const
		{
			return tree.size() == 0;
		}
		size_t size() const
		{
			return tree.size();
		}

		iterator begin()
		{
			return iterator(tree.findSamllest(this->tree.root), &tree.root);
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
			return iterator(NULL, &tree.root);
		}

		const_iterator end() const
		{
			return const_iterator(NULL, tree.root);
		}

		mapped_type &operator[](const key_type &k)
		{

			iterator iter = this->find(k);
			if (iter == this->end())
			{
				this->insert(ft::make_pair(k, mapped_type()));
			}
			iter = this->find(k);
			return (*iter).second;
		}

		iterator find(const key_type &k)
		{
			return iterator(this->tree.find(ft::pair<key_type, mapped_type>(k, mapped_type())), tree.root);
		}
		const_iterator find(const key_type &k) const
		{
			
			return const_iterator(this->tree.find(ft::pair<key_type, mapped_type>(k, mapped_type())), tree.root);
		}

		void erase(iterator position)
		{
			tree.remove(*position);
		}

		size_type erase(const key_type &k)
		{
			return tree.remove(ft::make_pair<Key, T>(k, T()));
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				tree.remove(*first);
				++first;
			}
		}

		void clear()
		{
			erase(this->begin(), this->end());
		}

		void swap(map &x)
		{
			node<value_type> *r1 = x.tree.root;
			size_t size1 = x.tree._size;

			x.tree.root = this->tree.root;
			this->tree.root = r1;

			x.tree._size = this->tree._size;
			this->tree._size = size1;
		}

		size_type count(const key_type &k) const
		{
			const_iterator c = this->find(k);
			if (c == this->end())
					return (0);
			return (1);
		}

		/*
			you can do it better if you search in redblack tree but haha i will not do it
		*/
		iterator lower_bound(const key_type &k)
		{
					iterator iter = this->begin();

					while (iter != this->end())
					{
						if (!_compare(iter->first, k))
							return iter;
							++iter;
					}
					return iter;
		}

		const_iterator lower_bound(const key_type &k) const
		{
					const_iterator iter = this->begin();

					while (iter != this->end())
					{
						if (!_compare(iter->first, k))
							return iter;
							++iter;
					}
					return iter;
		}

		iterator upper_bound(const key_type &k)
		{
				iterator iter = this->find(k);

				if (this->end() != iter)
				{
						++iter;
						return iter;
				}
				else
				{
					iter = this->begin();
				}

				while (iter != this->end())
				{
					if (!_compare(iter->first, k))
						return iter;
						++iter;
				}
				return this->end();
		}

		const_iterator upper_bound(const key_type &k) const
		{
				const_iterator iter = this->find(k);

				if (this->end() != iter)
				{
						++iter;
						return iter;
				}
				else
					iter = this->begin();
				while (iter != this->end())
				{
					if (!_compare(iter->first, k))
						return iter;
						++iter;
				}
				return this->end();
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
				return ft::make_pair<const_iterator, const_iterator>(lower_bound(k) , upper_bound(k));
		}

		pair<iterator, iterator> equal_range(const key_type &k)
		{
			return ft::make_pair<iterator, iterator>(lower_bound(k) , upper_bound(k));
		}

		allocator_type get_allocator() const
		{
			return this->my_alloc;
		}

		key_compare key_comp() const
		{
			return _compare;
		}

		value_compare value_comp() const
		{
			return value_compare(key_compare());
		}

		size_type max_size() const
		{
			return 100;
		}


		map& operator= (const map& x)
		{
			if (&x == this)
				return (*this);
			this->clear();
			this->insert(x.begin(), x.end());
			return (*this);
		}



		friend  bool operator ==(const map & lhr, const map &rhr)
		{

			if (&lhr == &rhr)
				return true;
			if (lhr.size() !=  rhr.size())
				return (false);

				const_iterator l = lhr.begin();
				const_iterator r = rhr.begin();
				while (true)
				{
					if (l == lhr.end() && r  == rhr.end())
					{
						return (true);
					}
					if (l == lhr.end() || r ==   rhr.end())
					{
						return (false);
					}
					if (l->first != r->first   ||  l->second != r->second)
					{
						return false;
					}
					++l;
					++r;
				}
				
		}

		
		friend  bool operator !=(const map & lhr, const map &rhr)
		{

				return !(lhr == rhr);
		}

		friend  bool operator >(const map & lhr, const map &rhr)
		{

				if (&lhr == &rhr)
				return false;
			 return   rhr < lhr;
		}
		friend  bool operator <(const map & lhr, const map &rhr)
		{
					 if (&lhr == &rhr)
				return false;
				return ft::lexicographical_compare<const_iterator,const_iterator>(lhr.begin(), lhr.end(), rhr.begin(), rhr.end());
		}

		friend  bool operator >=(const map & lhr, const map &rhr)
		{

				return !(lhr  < rhr);
		}
		friend  bool operator <=(const map & lhr, const map &rhr)
		{

				return !(rhr < lhr);
		}




		ft::RBtree<ft::pair<Key, T> , Allocator , Compare > tree;

	private:
		allocator_type my_alloc;
		key_compare _compare;
	};

};