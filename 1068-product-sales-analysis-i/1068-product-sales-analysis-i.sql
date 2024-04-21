# Write your MySQL query statement below
SELECT PRODUCT_NAME,YEAR,PRICE FROM SALES S JOIN PRODUCT P ON P.product_id=S.product_id;