# Write your MySQL query statement below
SELECT DISTINCT V.author_id AS ID FROM VIEWS V JOIN VIEWS V2 ON V.author_id=V2.viewer_id ORDER BY V.AUTHOR_ID; 