# Write your MySQL query statement below
-- select name as Employee from employee e where salary > (select salary from employee e1 where e1.id=e.managerId);

Select e2.name as Employee from employee e1 join employee e2 on e1.id=e2.managerId where e1.salary<e2.salary;