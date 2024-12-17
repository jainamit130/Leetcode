# Write your MySQL query statement below
Select E.name as Employee From Employee E left join Employee E1 on E.managerId = E1.id where E.salary>E1.salary;   