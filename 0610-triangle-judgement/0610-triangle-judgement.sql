# Write your MySQL query statement below
Select x,y,z,case When x+y>=z and y+z>=x and x+z>=y THEN "Yes" else "No" end as triangle From Triangle;