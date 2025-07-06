# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee where salary<(Select max(salary) from Employee);