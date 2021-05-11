class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		12
			点此或手机扫描二维码查看代码编写过程
			ACM编程题 语言限制[平均分17.5分 | 39人正确 / 58人做题 | 提交:38 次 得分：25.0 / 25.0
			标题：求最大连续bit数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
			【求最大连续bit数】
		功能 : 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
		 输入 : 一个byte型的数字
		  输出 : 无
		   返回 : 对应的二进制数字中1的最大连续数
				输入描述：
				输出描述：
				示例1：
				输入
				输出
		if (a == 1)
		{
			return a;
		}
		else if (b == 1)
		{
			return b;
		}
		while (a != b)
		{
			if (a>b)
			{
				a = a / 2;
			}
			else
			{
				b = b / 2;
			}
		}
		return a;
	}
};