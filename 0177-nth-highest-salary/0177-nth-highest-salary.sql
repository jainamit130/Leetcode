CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
   DECLARE nth_salary INT;
   with t as (Select Salary,ROW_NUMBER() OVER (ORDER BY SALARY DESC) as row_num From (Select Distinct Salary from Employee) AS DistinctSalaries)
   Select salary into nth_salary From t where row_num=N;
  RETURN nth_salary;
END


-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--     Declare nth int;
--     Select DISTINCT salary into nth from employee order by salary DESC LIMIT 1 OFFSET N-1;
--   RETURN nth;
-- END