class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int len = board.size();
		//检查行
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//检查列
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[j][i];
			if (sum == len)
				return true;
		}
		//检查主对角线
		int temp = 0;
		for (int i = 0; i<len; i++)
		{
			temp += board[i][i];
		}
		if (temp == len) return true;
		//检查副对角线
		temp = 0;
		for (int i = 0; i<len; i++)
			12
			点此或手机扫描二维码查看代码编写过程
			ACM编程题 语言限制[平均分14.7分 | 18人正确 / 44人做题 | 提交:1 次 得分：25.0 / 25.0
			标题：密码强度等级 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
			【密码强度等级】
			密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
		一、密码长度 :
		5 分 : 小于等于4 个字符
			10 分 : 5 到7 字符
			25 分 : 大于等于8 个字符
		二、字母 :
		0 分 : 没有字母
			10 分 : 全都是小（大）写字母
			20 分 : 大小写混合字母
		三、数字 :
		0 分 : 没有数字
			10 分 : 1 个数字
			20 分 : 大于1 个数字
		四、符号 :
		0 分 : 没有符号
			10 分 : 1 个符号
			25 分 : 大于1 个符号
		五、奖励 :
		2 分 : 字母和数字
			3 分 : 字母、数字和符号
			5 分 : 大小写字母、数字和符号
		最后的评分标准 :
		>= 90 : 非常安全
			>= 80 : 安全（Secure）
			>= 70 : 非常强
			>= 60 : 强（Strong）
			>= 50 : 一般（Average）
			>= 25 : 弱（Weak）
			>= 0 : 非常弱
			对应输出为：
			VERY_WEAK, WEAK,
			AVERAGE,
			STRONG,
			VERY_STRONG,
			SECURE,
			VERY_SECURE
			请根据输入的密码字符串，进行安全评定。
			注：
			字母：a - z, A - Z
		{
			temp += board[i][len - i - 1];
		}
		if (temp == len) return true;
		return false;
	}
};