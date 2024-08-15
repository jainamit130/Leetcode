# Write your MySQL query statement below
SELECT DepartmentName as Department,EmployeeName as Employee,Salary
FROM (
    SELECT E.name AS EmployeeName,
        E.salary AS Salary,
        D.name AS DepartmentName, DENSE_RANK() OVER (PARTITION BY E.departmentId ORDER BY salary DESC) AS `rank`
    FROM Employee E join Department D on E.departmentId=D.id
) AS ranked_employees
WHERE `rank` < 4;
