# Write your MySQL query statement below
SELECT U.PRODUCT_ID,IFNULL(ROUND(SUM(P.PRICE*U.UNITS)/SUM(U.UNITS),2),0) AS AVERAGE_PRICE FROM UNITSSOLD U RIGHT JOIN PRICES P ON P.PRODUCT_ID=U.PRODUCT_ID
AND U.purchase_date BETWEEN P.START_DATE AND P.END_DATE GROUP BY P.PRODUCT_ID;