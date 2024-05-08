# Write your MySQL query statement below
SELECT "Low Salary" as category,COUNT(*) as accounts_count FROM ACCOUNTS WHERE INCOME < 20000
UNION
SELECT "Average Salary" as category,COUNT(*) as accounts_count FROM ACCOUNTS WHERE INCOME >= 20000 and INCOME <= 50000
UNION
SELECT "High Salary" as category,COUNT(*) as accounts_count FROM ACCOUNTS WHERE INCOME > 50000;