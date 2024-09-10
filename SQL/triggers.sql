use org;
SELECT * FROM worker;
--FIRST CREATE THIS TABLE FOR LOGGING
CREATE TABLE logging_salary(NEW_SALARY INT (10),OLD_SALARY INT (10),SALARY_DIFFERENCE INT (10));
DELIMITER $$
--IN MYSQL YOU CAN'T DEFINE TRIGGERS FOR MULTIPLE COLUMNS
--10 PRECISION AND 2 SCALE (I.E. 0.99 AND IF 3 0.999) OF THE NUMBER
CREATE TRIGGER new_trigger
AFTER UPDATE ON worker
FOR EACH ROW
BEGIN
    DECLARE salary_difference DECIMAL(10,2);
    SET salary_difference = NEW.Salary - OLD.Salary;
    INSERT INTO logging_salary (new_salary, old_salary, salary_difference)
    VALUES (NEW.Salary, OLD.Salary, salary_difference);
END;
