
#pragma once
// #include "randomAccessIterator.hpp"
#include "iterator_traits.hpp"


namespace ft {
	template <class Iterator>
	class reverse_iterator
	{
		private:

		public:
			typedef Iterator	iterator_type;
			typedef typename Iterator::iterator_category iterator_category;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;


			Iterator iter;

            explicit reverse_iterator (iterator_type it)
            {
                this->iter = it.base();
            }



          template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->iter = rev_it.base();
            }



            // reverse_iterator(  iterator_type  c)  : iter(c)
            // {
            //         // this->iter = c;÷
            // }

                

                reverse_iterator( )
            {
                    // this->iter = c;
            }

            // iterator_type base() const
            // {
            //     return iter;
            // }

            reference  operator*()
            {
                return (*iter);
            }

            reverse_iterator  operator+(difference_type n) const
            {
                return reverse_iterator(iter -n + 1);
            }

      
            
            reverse_iterator  operator-(difference_type n) const
            {
                return reverse_iterator(iter - n + 1);
            }


             reverse_iterator  operator++() 
            {
                --iter;
                return (*this);
            }

            
             reverse_iterator  operator++(int) 
            {
                reverse_iterator tmp = *this;
                --(this->iter);
                return (tmp);
            }

            reverse_iterator  operator--() 
            {
                ++iter;
                return (*this);
            }

            reverse_iterator  operator--(int) 
            {
                reverse_iterator tmp = *this;
                ++(this->iter);
                return (tmp);
            }

            pointer				operator -> ()		const		
            { return (&(operator * ())); }



            reverse_iterator &operator+=(difference_type n)
            {
                iter -= n;
                return (*this);
            }

            reverse_iterator &operator-=(difference_type n)
            {
                iter +=n;
                return (*this);
            }


            Iterator base() const
            {
                return this->iter;
            }

        
        //    operator  reverse_iterator<>  ()  
        //     {
        //         return reverse_iterator<const Iterator>();
        //     }

            //  operator const reverse_iterator<const iterator_type>  () 
            // {
            //     return reverse_iterator<const iterator_type>(iter);
            // }
           operator  reverse_iterator<const  iterator_type>() 
            {
                return reverse_iterator<const iterator_type>(iter);
            }   
            
			template <class Iter, class Iter2>
			friend	bool		operator > (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() < rit.base()); }
			
			template <class Iter, class Iter2>
			friend	bool		operator < (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() > rit.base()); }
			
			template <class Iter, class Iter2>
			friend	bool		operator <= (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() >= rit.base()); }
			
			template <class Iter, class Iter2>
			friend	bool		operator >= (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() <= rit.base()); }

			template <class Iter, class Iter2>
			friend	bool		operator == (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() == rit.base()); }
			
			template <class Iter, class Iter2>
			friend	bool		operator != (reverse_iterator<Iter> const &lit, reverse_iterator<Iter2> const &rit)	{ return (lit.base() != rit.base()); }

			reference			operator [] (difference_type n)				{ return (*(iter - n)); }
			
			reverse_iterator &operator=(  reverse_iterator  &rit)  
			{
				this->iter = rit.iter;
				return (*this);
			}
			
			friend	reverse_iterator	operator + (difference_type a, const reverse_iterator &rit)
			{
				return (reverse_iterator(rit + a));
			}
			
			friend	difference_type		operator - (const reverse_iterator &lit, const reverse_iterator &rit)
			{
				return (rit.base() - lit.base());
			}
        







    };
};