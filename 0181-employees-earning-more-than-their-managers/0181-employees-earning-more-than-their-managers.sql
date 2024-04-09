# Write your MySQL query statement below
select name as Employee from employee e where salary > (select salary from employee e1 where e1.id=e.managerId);