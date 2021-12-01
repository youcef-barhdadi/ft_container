namespace ft{
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
};