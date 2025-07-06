SELECT 
    t.request_at AS Day,
    ROUND(
        SUM(CASE WHEN t.status = 'completed' THEN 0 ELSE 1 END) / COUNT(*),
        2
    ) AS 'Cancellation Rate'
FROM 
    trips t
JOIN 
    users u1 ON u1.users_id = t.client_id
JOIN 
    users u2 ON u2.users_id = t.driver_id
WHERE 
    u1.banned = 'No'
    AND u2.banned = 'No'
    AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 
    t.request_at;
