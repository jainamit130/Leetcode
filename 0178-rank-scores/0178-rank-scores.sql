# Write your MySQL query statement below
Select score,DENSE_RANK() OVER (ORDER BY score DESC) as "rank" From Scores;