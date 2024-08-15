# Write your MySQL query statement below
SELECT name  AS Customers  FROM Customers as c where c.id not in (SELECT customerId from orders) 