-- Select the Request_at date from the Trips table and calculate the cancellation rate
SELECT 
    tb1.Request_at as Day, 
    ROUND(
        SUM(
            CASE 
                WHEN tb1.Status = "completed" THEN 0
                ELSE 1
            END
        ) / count(*), -- Count the total number of trips
        2 -- Round the result to two decimal places
    ) as "Cancellation Rate"
    
-- Join the Trips table with the Users table twice to get information about the clients and drivers
FROM Trips as tb1
INNER JOIN Users as tb2
ON tb1.Client_Id = tb2.Users_Id AND tb2.Banned="No" -- Join with the Users table where Banned="No" for clients
INNER JOIN Users as tb3
ON tb1.Driver_Id = tb3.Users_Id AND tb3.Banned="No" -- Join with the Users table where Banned="No" for drivers

-- Filter the results for trips requested between October 1-3, 2013
WHERE tb1.Request_at BETWEEN "2013-10-01" AND "2013-10-03"

-- Group the results by Request_at date
GROUP BY tb1.Request_at

-- Order the results by Request_at date
ORDER BY Day