template<class T>
class Smart
{	
	Smart(const Smart& p)
	{
		_ptr = p.ptr;
		_conunt = p._count;
		mtx.lock();
		p.count++;
		mtx.unlock();

	}
	~Smart()
	{
		mtx.lock();
		-- _count;
		mtx.unlock();
		if (_count == 0)
		{
			delete _ptr;
		}
	}
};