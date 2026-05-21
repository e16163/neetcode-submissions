class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int start = 0; 
       int end = prices.size()-1;
       int profit = 0;
       int minBuy = 100;
       int maxSell = 0;
       while (start<end) 
       {
            minBuy = min(prices[start], minBuy);
            maxSell = max(prices[end], maxSell);
            if ((prices[start]-prices[start+1])>=(prices[end-1]-prices[end]))
            {
                start++;
            }
            else
            {
                end--;
            }
       }
       profit = maxSell - minBuy;
       if (profit<0)
       {
        profit = 0;
       }
       cout<<to_string(maxSell) + " "+ to_string(minBuy);
       return profit;
    }
};
