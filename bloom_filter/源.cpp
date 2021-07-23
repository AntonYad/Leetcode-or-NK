class BloomFilter
{
public:
    BloomFilter(size_t size)  // ��¡��������Ԫ�ظ���
        : _bmp(5 * size), _size(0)
    {}

    // ��������
    bool Insert(const K& key)
    {
        size_t index = KToInt1()(key) % (5 * size);
        _bmp.set(index);

        index= KToInt2()(key) % (5 * size);
        _bmp.set(index);
    
        index = KToInt3()(key) % (5 * size);
        _bmp.set(index);


        ++_size;
        return true;
    }
    // ����ڲ���
    bool IsInBloomFilter(const K& key)
    {
        size_t index = KToInt1()(key) % (5 * size);
        if (!_bmp.test(index))
        {
            return false;
        }

        index = KToInt2()(key) % (5 * size);
        if (!_bmp.test(index))
        {
            return false;
        }

        index = KToInt3()(key) % (5 * size);
        if (!_bmp.test(index))
        {
            return false;
        }
        return true;
    }
        // λͼ��֧��ɾ��
private:
    bitset _bmp;
    size_t _size;   // ʵ��Ԫ�صĸ���
};