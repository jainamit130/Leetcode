# Write your MySQL query statement below
with acceptance_rate as(
select requester_id as id from RequestAccepted
union all
select accepter_id as id from RequestAccepted
)

select id,count(id) as num
from acceptance_rate
group by id
order by count(id) desc
limit 1;