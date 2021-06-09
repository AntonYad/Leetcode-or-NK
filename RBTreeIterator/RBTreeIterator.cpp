template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* pNode)
		: _pNode(pNode)
	{}

	// �õ�������������ָ�����Ϊ
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
	//--��ʵ�ֹ������������˳�������Ϊ�ձ����������꣬STL�е�header������ָ�����Լ���ʵ����Ҫ���⴦��RED�����C����P�������ϵ���
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

		// ����ֵΪdata�Ľڵ�
		// ����ֵ���壺iterator�����²���ڵ�   bool�������ͷŲ���ɹ�
		pair<iterator, bool> Insert(const T& data);

		// Begin��End������
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

		// ������Ƿ�Ϊ�죬�Ƿ���true�����򷵻�false
		bool Empty()const;
		// ���غ��������Ч�ڵ�ĸ���
		size_t Size()const;
		// ��������е���Ч�ڵ�ɾ����ע�⣺ɾ��������Ч�ڵ㣬��ɾ��ͷ���
		void Clear();
		// �ں�����в���data�����ڸϻظýڵ��Ӧ�ĵ����������򷵻�End()
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