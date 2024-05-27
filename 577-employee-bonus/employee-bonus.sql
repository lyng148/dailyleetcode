/* Write your T-SQL query statement below */
SELECT name, bonus
FROM Employee e
FULL OUTER JOIN Bonus b
ON e.empId = b.empId
where b.bonus < 1000 OR b.bonus IS NULL