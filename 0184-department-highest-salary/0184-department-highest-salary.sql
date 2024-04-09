# Write your MySQL query statement below
SELECT D.name AS Department, E.name as Employee, E.Salary as Salary FROM EMPLOYEE E JOIN DEPARTMENT D ON D.ID=E.DEPARTMENTID WHERE E.SALARY=(SELECT MAX(SALARY) FROM EMPLOYEE C WHERE D.ID=C.DEPARTMENTID GROUP BY C.DEPARTMENTID);