# Write your MySQL query statement below
select round(sum(a.TIV_2016),2) as TIV_2016 from insurance a
where
a.TIV_2015 in (select b.TIV_2015 from insurance b where a.PID <> b.PID)
and
(a.LAT, a.LON) not in (select c.LAT, c.LON from insurance c where a.PID <> c.PID)
;