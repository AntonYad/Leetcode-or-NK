namespace GX
{
	//定义list类
	template<class T>
	struct _listnode{
		T _data;
		_listnode<T>* _next;
		_listnode<T>* _prev;

		_listnode(const T& x= T())
		:_prev(nullptr)
		, _next(nullptr)
		, _data(x)
		{
		}
	};
	//const& stl底层实现类设计的复用
	template<class T, class Ref, class Ptr>
	struct _listnode
	{
		// <T, T&, T*> iterator
		typedef  _listnode<T>node;
		// <T, const T&, const T*> const_iterator
		typedef _listnode<T, Ref, Ptr>self;
		node* _node;
		_listnode(node*node)
			:_node(node)
		{}
		//!= ==
		bool operator != (const self& s)const
		{
			return _node != self._node;
		}
		bool operator == (const self&s)const
		{
			return _node == self._node;
		}
		// operator-> *
		Ref operator*()//T&
		{
			return _node->_data; 
		}
		T* operator->()//Ptr operator
		{ 
			return &(operator*()); 
		}
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self& opeartor--()
		{
			_node = _node->prev;
			return *this;
		}
		template<class T>
		class list
		{
			typedef _listnode<T> node;
		public:
			typedef __list_iterator<T, T&, T*> iterator;
			typedef __list_iterator<T, const T&, const T*> const_iterator;

			iterator begin()
			{
				return _head->_next;
			}
			iterator end()
			{
				return _head;
			}
			const_ iterator begin()const
			{
				return _head->_next;
			}
			const_iterator end()const
			{
				return _head;
			}
			list()
			{
				_head = new node;
				_node->_next = _head;
				_head->_next = _node;  
			}
			void push_back(const T& s)
			{
				node* newnode = new node(x);
				node* tail = _head->_prev;
				tail->next = newnode;
				newnode->_prev = tail;
				newnode->_next = _head;
				_head->_prev = newnode;
			}
			~list()
			{
				delete[] _head;
				_head = nullptr;
			}
			//void swap(const T& x)
			//{
			//	swap(_node,x)
			//}
			size_t size()
			{
				node* p = _head->next;
				while (p != _head->prev)
				{
					size++;
					p = p->_next;
				}
				return size;
			}
			bool empty()
			{
				return size() == 0;
			}
			iterator insert(iterator pos, T& x)
			{
				node* newnode = new  node(val);
				node* cur = pos._node;
				newnode->_next = pos._node;
				pos._node->prev->next = newnode;
				newnode->prev = pos._node->prev;
				pos._node->prev = newnode;
				return iterator(newnode);
			}
			iterator erase(iterator pos)
			{
				node *cur = pos._node;
				node *next = cur->next;
				pos._node->prev->next = pos._node->next;
				pos.node->next->prev = pos._node->prev;
				delete cur;
				return iterator(next);
			}
		private:
			node* _head;
		}
	}
};


}
int main()
{
	list<int> l1;  //实例化对象构造空的l1
	list<int> l2(1, 100); //构造l2 并且载入4个为100的节点
	list<int> l3(l2.begin(), l2.end());// 构造从l2begin到l2end的链表
	list<int> l4(l3);//用l3构建l4
	//nums为一个数组
	list<int> l5(nums, nums + sizeof(nums) / sizeof(int));
	//从nums.begin开始到nums.end构建l5

	for (list<int>::iterator it = l.begin(); it != l.end)
	{
		cout << *it << " ";
	}
	//逆向
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend())
	{
		cout << *it << " ";
	}
	//尾插
	l.push_back(4);
	//pop则和数据结构一样删除尾节点
	l.pop_back();
	l.insert(pos, 4);//pos前插入data为4的节点
	l.insert(pos, 4, 4);//pos前插入四个data为4的节点
	l.erase(pos);
	l.erase(l.begin(), l.end());
	//删除区间内的节点
	l1.swap(l2);

	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给
		其赋值
			l.erase(it);
		++it;
	}
	//修改后
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}