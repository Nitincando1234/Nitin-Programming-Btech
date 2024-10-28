--Write the query for implementing the following functions: MAX (), MIN (), AVG () and COUNT ()
use ORG;
SELECT * FROM worker;
INSERT INTO worker VALUES
(012,'Sophia', 'Brown', 51000, '2022-02-05 08:30:00', 'IT'),
(013,'Aiden', 'Clark', 52000, '2022-03-10 09:00:00', 'HR'),
(014,'Isabella', 'Lewis', 53000, '2022-04-15 10:15:00', 'Finance'),
(015,'Ethan', 'Walker', 54000, '2022-05-20 11:30:00', 'Marketing'),
(016,'Mia', 'Hall', 55000, '2022-06-25 12:00:00', 'Sales'),
(017,'Liam', 'Young', 56000, '2022-07-30 13:15:00', 'Support'),
(018,'Olivia', 'King', 57000, '2022-08-10 14:30:00', 'R&D'),
(019,'Noah', 'Scott', 58000, '2022-09-15 15:00:00', 'Logistics'),
(020,'Ava', 'Adams', 59000, '2022-10-20 16:15:00', 'Production'),
(021,'Lucas', 'Baker', 60000, '2022-11-25 17:30:00', 'Management'),
(022,'Emily', 'Carter', 61000, '2023-01-10 08:45:00', 'HR'),
(023,'Benjamin', 'Mitchell', 62000, '2023-02-15 09:15:00', 'Finance'),
(024,'Madison', 'Perez', 63000, '2023-03-20 10:30:00', 'Marketing'),
(025,'Mason', 'Roberts', 64000, '2023-04-25 11:45:00', 'Sales'),
(026,'Harper', 'Murphy', 65000, '2023-05-30 13:00:00', 'Support'),
(027,'James', 'Cook', 66000, '2023-06-10 14:15:00', 'R&D'),
(028,'Ella', 'Bennett', 67000, '2023-07-15 15:30:00', 'Logistics'),
(029,'Alexander', 'Gonzalez', 68000, '2023-08-20 16:45:00', 'Production'),
(030,'Sofia', 'Ward', 69000, '2023-09-25 18:00:00', 'Management'),
(031,'Jacob', 'Nelson', 70000, '2023-10-30 19:15:00', 'IT'),
(032,'Avery', 'Hall', 71000, '2023-11-05 20:30:00', 'HR'),
(033,'William', 'Phillips', 72000, '2023-12-10 08:00:00', 'Finance'),
(034,'Chloe', 'Sanchez', 73000, '2023-12-15 09:15:00', 'Marketing'),
(035,'Michael', 'Parker', 74000, '2024-01-05 10:30:00', 'Sales'),
(036,'Charlotte', 'Watson', 75000, '2024-02-10 11:45:00', 'Support'),
(037,'Daniel', 'Cooper', 76000, '2024-03-15 13:00:00', 'R&D'),
(038,'Amelia', 'Richards', 77000, '2024-04-20 14:15:00', 'Logistics'),
(039,'Ethan', 'Foster', 78000, '2024-05-25 15:30:00', 'Production'),
(040,'Grace', 'Wood', 79000, '2024-06-30 16:45:00', 'Management'),
(041,'Jack', 'Young', 80000, '2024-07-10 18:00:00', 'IT'),
(042,'Zoe', 'Ward', 81000, '2024-08-20 19:15:00', 'HR'),
(043,'Logan', 'Cox', 82000, '2024-09-15 20:30:00', 'Finance'),
(044,'Lily', 'Gray', 83000, '2024-10-05 08:00:00', 'Marketing'),
(045,'Ryan', 'Jenkins', 84000, '2024-11-10 09:15:00', 'Sales'),
(046,'Aria', 'Hughes', 85000, '2024-12-15 10:30:00', 'Support'),
(047,'Noah', 'Sullivan', 86000, '2024-01-20 11:45:00', 'R&D'),
(048,'Samantha', 'Price', 87000, '2024-02-25 13:00:00', 'Logistics'),
(049,'Aiden', 'Mitchell', 88000, '2024-03-30 14:15:00', 'Production'),
(050,'Evelyn', 'Parker', 89000, '2024-04-05 15:30:00', 'Management');


SELECT `Department`,MAX(SALARY) FROM worker GROUP BY `Department`;
SELECT `Department`,MIN(SALARY) FROM worker GROUP BY `Department`;
SELECT `Department`,AVG(SALARY) FROM worker GROUP BY `Department`;
SELECT `Department`,COUNT(`Department`) FROM worker GROUP BY `Department`;