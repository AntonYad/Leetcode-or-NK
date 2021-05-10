namespace GX
{
	//����list��
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
	//const& stl�ײ�ʵ������Ƶĸ���
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
	list<int> l1;  //ʵ����������յ�l1
	list<int> l2(1, 100); //����l2 ��������4��Ϊ100�Ľڵ�
	list<int> l3(l2.begin(), l2.end());// �����l2begin��l2end������
	list<int> l4(l3);//��l3����l4
	//numsΪһ������
	list<int> l5(nums, nums + sizeof(nums) / sizeof(int));
	//��nums.begin��ʼ��nums.end����l5

	for (list<int>::iterator it = l.begin(); it != l.end)
	{
		cout << *it << " ";
	}
	//����
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend())
	{
		cout << *it << " ";
	}
	//β��
	l.push_back(4);
	//pop������ݽṹһ��ɾ��β�ڵ�
	l.pop_back();
	l.insert(pos, 4);//posǰ����dataΪ4�Ľڵ�
	l.insert(pos, 4, 4);//posǰ�����ĸ�dataΪ4�Ľڵ�
	l.erase(pos);
	l.erase(l.begin(), l.end());
	//ɾ�������ڵĽڵ�
	l1.swap(l2);

	auto it = l.begin();
	while (it != l.end())
	{
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ�
		�丳ֵ
			l.erase(it);
		++it;
	}
	//�޸ĺ�
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}