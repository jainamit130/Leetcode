# Write your MySQL query statement below
SELECT distinct a.id,
CASE
When a.p_id is null then 'Root'
when a.p_id is not null and b.p_id is not null then 'Inner'
else 'Leaf'
end as type
from tree a left outer join tree b on (a.id=b.p_id);