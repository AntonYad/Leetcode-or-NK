int GetUglyNumber_Solution(int index) {
    if (index < 7) return index;
    vector<int> result(index, 0);
    result[0] = 1;
    int indexTwo = 0, indexThree = 0, indexFive = 0;
    for (int i = 1; i < index; ++i) {
        int minNum = min(min(result[indexTwo] * 2, result[indexThree] * 3), result[indexFive] * 5);
        if (minNum == result[indexTwo] * 2) indexTwo++;
        if (minNum == result[indexThree] * 3) indexThree++;
        if (minNum == result[indexFive] * 5) indexFive++;
        result[i] = minNum;
    }
    return result[index - 1];

}
