class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int len = board.size();
		//�����
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//�����
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[j][i];
			if (sum == len)
				return true;
		}
		//������Խ���
		int temp = 0;
		for (int i = 0; i<len; i++)
		{
			temp += board[i][i];
		}
		if (temp == len) return true;
		//��鸱�Խ���
		temp = 0;
		for (int i = 0; i<len; i++)
			12
			��˻��ֻ�ɨ���ά��鿴�����д����
			ACM����� ��������[ƽ����14.7�� | 18����ȷ / 44������ | �ύ:1 �� �÷֣�25.0 / 25.0
			���⣺����ǿ�ȵȼ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
			������ǿ�ȵȼ���
			���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
		һ�����볤�� :
		5 �� : С�ڵ���4 ���ַ�
			10 �� : 5 ��7 �ַ�
			25 �� : ���ڵ���8 ���ַ�
		������ĸ :
		0 �� : û����ĸ
			10 �� : ȫ����С����д��ĸ
			20 �� : ��Сд�����ĸ
		�������� :
		0 �� : û������
			10 �� : 1 ������
			20 �� : ����1 ������
		�ġ����� :
		0 �� : û�з���
			10 �� : 1 ������
			25 �� : ����1 ������
		�塢���� :
		2 �� : ��ĸ������
			3 �� : ��ĸ�����ֺͷ���
			5 �� : ��Сд��ĸ�����ֺͷ���
		�������ֱ�׼ :
		>= 90 : �ǳ���ȫ
			>= 80 : ��ȫ��Secure��
			>= 70 : �ǳ�ǿ
			>= 60 : ǿ��Strong��
			>= 50 : һ�㣨Average��
			>= 25 : ����Weak��
			>= 0 : �ǳ���
			��Ӧ���Ϊ��
			VERY_WEAK, WEAK,
			AVERAGE,
			STRONG,
			VERY_STRONG,
			SECURE,
			VERY_SECURE
			���������������ַ��������а�ȫ������
			ע��
			��ĸ��a - z, A - Z
		{
			temp += board[i][len - i - 1];
		}
		if (temp == len) return true;
		return false;
	}
};