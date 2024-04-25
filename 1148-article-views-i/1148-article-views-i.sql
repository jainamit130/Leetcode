# Write your MySQL query statement below
SELECT author_id AS ID FROM VIEWS WHERE author_id=viewer_id GROUP BY author_id,viewer_id ORDER BY AUTHOR_ID; 