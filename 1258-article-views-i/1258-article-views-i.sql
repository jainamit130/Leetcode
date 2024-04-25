# Write your MySQL query statement below
-- SELECT DISTINCT author_id AS ID FROM VIEWS GROUP BY author_id,viewer_id HAVING author_id=viewer_id ORDER BY AUTHOR_ID; 

SELECT author_id AS id
FROM Views
WHERE author_id = viewer_id
GROUP BY author_id
ORDER BY author_id;