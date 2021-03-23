#include "Solution123.h"

int Solution123::maxProfit(vector<int>& prices) {
	/*
	**  ���������˽��״���ֻ���� 2 ��
	*	һ������ 4 ��״̬
	*	buy1_i: �� i ��ֻ���й�һ������������������
	*	sell1_i�� �� i �����һ�����롢һ�������������������
	*	buy2_i: �� i �������һ�����롢һ����������һ��������������
	*	sell2_i: �� i �������һ�����롢һ����������һ�����롢��һ���������������
	*	״̬ת�Ʒ��̣�
	*		buy1_(i+1) = max{ buy1_i, -price[i] }
	*		sell1_(i+1) = max{ sell1_i, buy1_i + price[i+1] }
	*		buy2_(i+1)  = max{ buy2_i, sell1_i - price[i+1] }
	*		sell2_(i+1) = max{ sell2_i, buy2_i + price[i+1] }
	*/
	int buy1 = -prices[0];
	int sell1 = 0;
	int buy2 = -prices[0];
	int sell2 = 0;
	for (int i = 1; i < prices.size(); i++) {
		buy1 = max(buy1, -prices[i]);
		sell1 = max(sell1, buy1 + prices[i]);
		buy2 = max(buy2, sell1 - prices[i]);
		sell2 = max(sell2, buy2 + prices[i]);
	}
	return sell2;
}