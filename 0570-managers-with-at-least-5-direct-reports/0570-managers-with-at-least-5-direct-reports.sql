# Write your MySQL query statement below
SELECT name from Employee where id in (SELECT managerId FROM EMPLOYEE GROUP BY managerId having count(*)>=5);  