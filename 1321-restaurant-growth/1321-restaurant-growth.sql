# Write your MySQL query statement below
SELECT C.VISITED_ON,SUM(AMOUNT) AS AMOUNT,ROUND(SUM(AMOUNT)/7,2) AS average_amount  FROM (
SELECT DISTINCT VISITED_ON 
FROM CUSTOMER T WHERE 
DATEDIFF(visited_on,(select min(visited_on) from customer)) >= 6
) V LEFT JOIN CUSTOMER C ON DATEDIFF(V.VISITED_ON,C.VISITED_ON) BETWEEN 0 AND 6 GROUP BY V.VISITED_ON ORDER BY V.visited_on;;   