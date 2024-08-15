# Write your MySQL query statement below
Select name as "Employee" from Employee E where salary>(Select salary from Employee where id=E.managerId); 