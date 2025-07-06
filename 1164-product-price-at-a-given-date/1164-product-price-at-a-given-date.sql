# Write your MySQL query statement below
Select Distinct product_id,10 as price from Products 
group by product_id having min(change_date) > "2019-08-16"

union 

select p2.product_id,new_price as price from products p2
where (p2.product_id,p2.change_date) in (
    Select product_id,max(change_date) from products where change_date<="2019-08-16"
    group by product_id
);
