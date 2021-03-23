#include "Solution123.h"

int Solution123::maxProfit(vector<int>& prices) {
	/*
	**  由于限制了交易次数只能是 2 次
	*	一共存在 4 种状态
	*	buy1_i: 第 i 天只进行过一次买入操作的最大利润
	*	sell1_i： 第 i 天进行一次买入、一次卖出操作的最大利润
	*	buy2_i: 第 i 天进行了一次买入、一次卖出、又一次买入的最大利润
	*	sell2_i: 第 i 天进行了一次买入、一次卖出、又一次买入、又一次卖出的最大利润
	*	状态转移方程：
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