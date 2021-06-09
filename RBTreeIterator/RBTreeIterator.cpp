template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* pNode)
		: _pNode(pNode)
	{}

	// 让迭代器具有类似指针的行为
	T& operator*()
	{
		return _node->data;
	}
	T* operator->()
	{
		return &(operator*());
	}
		Self& operator++()
		{
			if (_node->_right)
			{
				Node* cur = _node->_right;
				while (cur && cur->_left)
				{
					cur = cur->_left;
				}

				_node = cur;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_right == cur)
				{
					cur = parent;
					parent = parent->_parent;
				}

				_node = parent;
			}
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			Self& operator++(this);
			return temp;
		}
	bool operator!=(const Self s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)const
	{
		return !(_node != s._node;);
	}
	//--的实现过程是右中左的顺序，如果左为空表明树访问完，STL中的header中左右指向与自己是实现需要特殊处理（RED）如果C不是P的左向上迭代
private:
	Node* _pNode;
};






	template<class T, class KeyOfValue>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef RBTreeIterator<T> iterator;
	public:
		RBTree()
			: _size(0)
		{
			_pHead = new Node;
			_pHead->_pLeft = _pHead;
			_pHead->_pRight = _pHead;
		}

		// 插入值为data的节点
		// 返回值含义：iterator代表新插入节点   bool：代表释放插入成功
		pair<iterator, bool> Insert(const T& data);

		// Begin和End迭代器
		Iterator Begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			return Iterator(cur);
		}

		Iterator End()
		{
			return Iterator(nullptr);
		}

		// 红黑树是否为红，是返回true，否则返回false
		bool Empty()const;
		// 返回红黑树中有效节点的个数
		size_t Size()const;
		// 将红黑树中的有效节点删除，注意：删除的是有效节点，不删除头结点
		void Clear();
		// 在红黑树中查找data，存在赶回该节点对应的迭代器，否则返回End()
		iterator Find(const T& data);

	private:
		Node* _LeftMost();
		Node* _RightMost();
		void _Destroy(Node*& pRoot);
		void RotateL(Node* pParent);
		void RotateR(Node* pParent);
	private:
		Node* _pHead;
		size_t _size;
	};