# Write your MySQL query statement below

SELECT L1.NUM AS ConsecutiveNums  FROM LOGS L1,LOGS L2,LOGS L3 WHERE L1.ID=L2.ID-1 AND L3.ID-1=L2.ID AND L1.NUM=L2.NUM AND L2.NUM=L3.NUM; 


/*

+----+-----+        
| id | num |        +----+-----+
+----+-----+        | id | num |
| 1  | 1   |        +----+-----+ 
| 2  | 1   |        | 1  | 1   | 
| 3  | 1   |        | 2  | 1   | 
| 4  | 2   |        | 3  | 1   | 
| 5  | 1   |        | 4  | 2   | 
| 6  | 2   |        | 5  | 1   | 
| 7  | 2   |        | 6  | 2   | 
+----+-----+        | 7  | 2   | 
                    +----+-----+ 








*/