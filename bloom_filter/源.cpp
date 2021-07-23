class BloomFilter
{
public:
    BloomFilter(size_t size)  // 布隆过滤器中元素个数
        : _bmp(5 * size), _size(0)
    {}

    // 插入数据
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
    // 检测在不在
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
        // 位图不支持删除
private:
    bitset _bmp;
    size_t _size;   // 实际元素的个数
};