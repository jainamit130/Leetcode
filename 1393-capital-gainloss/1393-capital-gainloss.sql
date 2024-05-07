# Write your MySQL query statement below
SELECT STOCK_NAME,sum(case when operation='Sell' then price*(-1) else price end)*-1 as capital_gain_loss from STOCKS group by STOCK_NAME; 