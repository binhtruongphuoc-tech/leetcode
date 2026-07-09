#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    

    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;
    
    for (int i = 1; i < pricesSize; i++) {

        
        buy1  = MAX(buy1, -prices[i]);
        sell1 = MAX(sell1, buy1 + prices[i]);
        
        buy2  = MAX(buy2, sell1 - prices[i]);
        sell2 = MAX(sell2, buy2 + prices[i]);
    }
    
    return sell2;
}