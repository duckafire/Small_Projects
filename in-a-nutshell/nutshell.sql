----------------------------------------------------------------------------------------

-- it is a line comment

/* it is a block comment */

-- SQL: Structured Query Language
-- * DCL: Data Control Language      - GRANT, DENY, REVOKE
-- * DDL: Data Definition Language   - CREATE, ALTER and DROP
-- * DML: Data Manipulation Language - INSERT, UPDATE and DELETE
-- * DQL: Data Query Language        - SELECT
-- * DTL: Data Transaction Language  - BEGIN/SET TRANSACTION; COMMIT; ROLLBACK; SAVEPOINT

-- 'string' | "property with special characters"

----------------------------------------------------------------------------------------

GRANT CREATE, SELECT ON sql_in_a_nutshell TO foo_user;

DENY INSERT, UPDATE, DELETE ON sql_in_a_nutshell TO foo_user;

REVOKE CREATE ON sql_in_a_nutshell FROM foo_user;

----------------------------------------------------------------------------------------

CREATE DATABASE sql_in_a_nutshell;
USE sql_in_a_nutshell;

CREATE TABLE nutshell_core {
	id INT PRIMARY KEY UNIQUE AUTO_INCREMENT,
	num INT DEFAULT 0 COMMENT 'Property named as "num"',
	foo INT NOT NULL, -- it cannot be null
};

CREATE TABLE other_nutshell {
	foo INT NULL,
	bar INT NULL,
};

ALTER nutshell_core
ADD bar INT NULL, -- it can be null
MODIFY num INT DEFAULT 1, -- no comment
RENAME COLUMN id TO unique_id,
DROP COLUMN foo,
RENAME nutcore; -- rename the table

DROP TABLE nutcore;

----------------------------------------------------------------------------------------

INSERT INTO other_nutshell VALUES ( 0, 1 ); -- to "foo" and "bar"

INSERT INTO other_nutshell ( bar ) VALUES ( -300 ); -- to "bar"; "foo" = NULL

-- update all table cells
-- UPDATE other_nutshell
-- SET foo = -1, bar = -1;

UPDATE other_nutshell
SET foo = -1, bar = -1
WHERE foo != bar;

-- clear the table
-- DELETE FROM other_nutshell;

DELETE FROM other_nutshell
WHERE foo = 15; -- equal

----------------------------------------------------------------------------------------

-- get all cells value
SELECT * FROM other_nutshell;

SELECT bar FROM other_nutshell;

SELECT foo FROM other_nutshell
WHERE foo > 0 AND bar IS NOT NULL;

SELECT foo AS f, bar FROM other_nutshell
WHERE (f IS NOT NULL) + (bar IS NOT NULL) = 1; -- som of boolean values

----------------------------------------------------------------------------------------

-- define that transaction can interfere in the process of read and record
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- a transaction in record in the data base is done only
-- if "none" error occur until the end of the process
BEGIN TRANSACTION

	BEGIN TRY
		
		INSERT INTO other_nutshell ( 9 ); -- to "foo"

		SAVEPOINT back_to_save_point;

		INSERT INTO other_nutshell ( bar ) VALUES ( 49 ); -- to "foo"

	END TRY
	BEGIN CATCH
		
		-- revert the transaction operations
		ROLLBACK;
		
		PRINT 'An error occur!';

	END CATCH;

	BEGIN TRY
		
		INSERT INTO other_nutshell ( bar ) VALUES ( 'bar' );

	END TRY
	BEGIN CATCH
		
		-- different of `goto`; revert the insertion of 49 in "bar"
		ROLLBACK back_to_save_point;

		-- revert ALL process
		-- ROLLBACK;
		
		PRINT 'An error occur!';

	END CATCH;

COMMIT; -- end of BEGIN TRANSACTION

----------------------------------------------------------------------------------------
