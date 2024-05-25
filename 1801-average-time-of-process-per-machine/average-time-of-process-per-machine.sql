SELECT
    a1.machine_id AS machine_id,
    ROUND(AVG(CAST(a2.timestamp - a1.timestamp AS FLOAT)), 3) AS processing_time
FROM Activity a1
JOIN Activity a2 ON a1.machine_id = a2.machine_id
                AND a1.process_id = a2.process_id
                AND a1.activity_type != a2.activity_type
                AND a2.timestamp > a1.timestamp
GROUP BY a1.machine_id
ORDER BY machine_id DESC;