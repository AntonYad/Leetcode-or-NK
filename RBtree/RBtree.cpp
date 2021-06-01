enum Color {
	RED, 
	BLACK 
};
template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
};
template<class T>
class RBtree
{
	typedef RBTreeNode<T> Node;
	// �ں�����в���ֵΪdata�Ľڵ㣬����ɹ�����true�����򷵻�false
	// ע�⣺Ϊ�˼����������ʵ�ֺ�������洢�ظ���Ԫ��
	bool Insert(const T& data)
	{
		Node* _root = GetRoot();
		if (_root == nullptr)
		{
			Node* _root = Node(data);
			return true
		}
		else
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_data > data)
				{
					cur = cur->_pLeft;
				}
				else
				{
					cur = cur->_pRight;
				}
			}
			Node* New = new Node(data);
			cur = New;
			if (parent->_data > data)
			{
				parent->_pLeft = cur;
				cur->_pParent = parent;
			}
			else
			{
				parent->_pRight = cur;
				cur->_pParent = parent;
			}
			while (parent != _pHead && parent->_color == RED)
			{
				Node* grandfather = parent->_pParent;
				if (grandfather->_pLeft == parent)
				{
					Node* uncle = grandfather->_pRight;
					if (uncle && uncle->_color == RED)
					{
						uncle->_color == BLACK;
						parent->_color == BLACK;
						grandfather->_color == RED;
						cur = grandfather;
						parent = cur->_pParent;
					}
					else//uncle not exists  black
					{
						if (cur = parent->_pLeft)
						{
							//�ҵ���
							RotateR(grandfather);
							parent->_color = BLACK;
							grandfather->_color = RED;
						}
						else
						{
							//˫��ת
							RotateL(parent);
							RotateR(grandfather);
							cur->_color = BLACK;
							grandfather->_color = RED;
						}
					}
				}
				//uncle  left
				else
				{
					if (cur == parent->_pRight)
					{
						RotateL(grandfather);
						grandfather->_color = RED;
						parent->_color = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_color = BLACK;
						grandfather->_color = RED;
					}
				}
				break;
			}
		}
		_root->_color = BLACK;
		return true;
	}

	// ����������Ƿ����ֵΪdata�Ľڵ㣬���ڷ��ظýڵ�ĵ�ַ�����򷵻�nullptr
	Node* Find(const T& data)
	{
		Node* cur = _pHead->_pParent;
		if (cur->_data == data)
		{
			return cur;
		}
		Find(cur->_pLeft);
		Find(cur->_pRight);
		return nullptr;
	}

	// ��ȡ����������ڵ�
	Node* LeftMost()
	{
		Node* root = _pHead->_pParent;
		Node* parent = nullptr;
		while (root)
		{
			parent = root;
			root = root->_pLeft;
		}
		return parent;
	}

	// ��ȡ��������Ҳ�ڵ�
	Node* RightMost()
	{
		Node* root = _pHead->_pParent;
		Node* parent = nullptr;
		while (root)
		{
			parent = root;
			root = root->_pRight;
		}
		return parent;
	}
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	// ��������Ƿ�Ϊ��Ч�ĺ������ע�⣺���ڲ���Ҫ����_IsValidRBTRee�������
	bool IsValidRBTRee()
	{
		if (_pHead->_pParent && _pHead->_pParent->_color == RED)
		{
			return false;
		}

		int blacknum = 0;
		Node* cur = _pHead->_pParent;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++blacknum;
			}
			cur->_pLeft;
		}
		int num = 0;
		return _CheckRedCol(_root)
			&& _CheckBlackNum(_root, num, blacknum);
	}
private:
	bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (pRoot == nullptr)
		{
			return blackCount==pathBlack;
		}
		if (pRoot->_color == BLACK)
		{
			blackCount++;
		}

		return  _CheckBlackNum(root->_left, blackCount, pathBlack)
			&& _CheckBlackNum(root->_right, blackCount, pathBlack);
	}
	// ����
	void RotateL(Node* pParent)
	{
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;
		pParent->_pRight = subR;
		if (subRL)
		{
			subRL->_pParent = pParent;
		}
		subR->_left = pParent;
		pParent->_pParent = subR;
		Node* grandfather = pParent->_pParent;
		if (pParent == _pHead->_pParent)
		{
			_pHead->_pParent = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (grandfather->_pLeft == pParent)
			{
				grandfather->_pLeft = subR;
				subR->_pParent = grandfather;
			}
			else
			{
				grandfather->_pRight = subR;
				subR->_pParent = grandfather;
			}
		}
	}
	// �ҵ���
	void RotateR(Node* pParent)
	{
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;
		pParent->_pLeft = subL;
		if (subLR)
		{
			subL->_pParent = pParent;
		}
		subL->_pRight = pParent;
		pParent->_pParent = subL;
		Node* grandfather = pParent->_pParent;
		subL->_pRight = pParent;
		pParent->_pParent = subL;
		if (pParent == _pHead->_pParent)
		{
			_pHead->_pParent=subL;
			subL->_pParent = _pHead;
		}
		else
		{
			if (grandfather->_pLeft == pParent)
			{
				grandfather->_pLeft = subL;
				subL->_pParent = grandfather;
			}
			else
			{
				grandfather->_pRight = subL;
				subL->_pParent = grandfather;
			}
		}
	}
	// Ϊ�˲��������������ȡ���ڵ�
	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
};