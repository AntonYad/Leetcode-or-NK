namespace Close_Hash
{
	enum State { EMPTY, EXIST, DELETE };

	template<class K, class V>
	class HashTable
	{
		struct Elem
		{
			pair<K, V> _val;
			State _state;
		};

	public:
		HashTable(size_t capacity = 3)
			: _ht(capacity), _size(0), _totalSize(0)
		{
			for (size_t i = 0; i < capacity; ++i)
				_ht[i]._state = EMPTY;
		}

		// ²åÈë
		bool Insert(const pair<K, V>& val)
		{
			if (_size || _size == (10 * _size) / _totalSize == 7)
			{
				size_t newsize = _size == 0 ? 10 : _totalSize * 2;
				HashTable<K, V> newht;
				newht._ht.resize(newsize, EMPTY);
				for (int i = 0; i < _ht.size(); i++)
				{
					if (_ht[i].state == EXIST)
						newht.Insert(_ht[i]._val);
				}
				_ht.swap(newht._ht);
			}

			int statr = HashFunc(val ) ;
			int index = start;
			int i = 1;
			while (_ht[index]._state!=EMPTY)
			{
				index = statr + i;
				index %= _ht.size();
				i++;
			}
			_ht[index]._val = val;
			_ht[index]._state = EXIST;
			return true;
		}
		// ²éÕÒ
		size_t Find(const K& key)
		{
			
			size_t start = HashFunc(key);
			size_t index = start;
			int j = 1;
			for (int i = 0; i < _ht.size(); i++)
			{
				if (_ht[index]._state == EXIST && _ht[index]._val == key)
				{
					return index;
				}
				index = statr + j;
				index %= _ht.size();
				j++;
			}
			return -1;
		}

		// É¾³ý
		bool Erase(const K& key)
		{
			size_t res = Find(key);
			if (res > 0)
			{
				_ht[res]._state = DELETE;
				return true;
			}
			return false;
		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty() const
		{
			return _size == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			swap(_totalSize, ht._totalSize);
			_ht.swap(ht._ht);
		}

	private:
		size_t HashFunc(const K& key)
		{
			return key % _ht.capacity();
		}
	private:
		vector<Elem> _ht;
		size_t _size;
		size_t _totalSize;  
	};
}