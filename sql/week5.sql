use dbms;
create table employee2 (
    fname VARCHAR(50),
    minit CHAR(1),
    lname VARCHAR(50),
    ssn CHAR(9) PRIMARY KEY,
    bdate DATE,
    address VARCHAR(100),
    sex CHAR(1),
    salary DECIMAL(10, 2),
    super_ssn CHAR(9),
    dno INT
);

insert into employee2 values
    ('John', 'D', 'Doe', '123', '1990-05-15', 'chennai', 'M', 60000, '150', 1),
    ('Jane', 'E', 'Smith', '124', '1985-08-25', 'bangalore', 'F', 55000, '151', 2),
    ('David', 'J', 'Johnson', '125', '1992-03-10', 'hyderabad', 'M', 70000, '152', 1),
     ('pinky', 'J', 'Johny', '126', '1999-05-12', 'Hyderabad', 'F', 75000, '153', 2);

select * from employee2; 

create table department2 (
    dname VARCHAR(50),
    dnumber INT PRIMARY KEY,
    mgr_ssn CHAR(9),
    mgr_start_date DATE
);

insert into department2 values
    ('HR', 1, '123', '2023-01-15'),
    ('IT', 2, '124', '2022-08-25'),
    ('Sales', 3, '125', '2023-03-10'),
    ('Marketing', 4, '126', '2021-12-05');

select * from department2;

create table Dep_Locations (
    dnumber INT,
    dlocation VARCHAR(100)
);


insert into Dep_Locations values
    (1, 'chennai'),
    (2, 'banagalore'),
    (3, 'chennai'),
    (4, 'pune');

select * from Dep_locations;

create table Project (
    pname VARCHAR(100),
    pnumber INT PRIMARY KEY,
    plocation VARCHAR(100),
    Dnum INT
);


insert into Project values
    ('Project A', 1, 'chennai', 1),
    ('Project B', 2, 'hyderabad', 2),
    ('Project C', 3, 'kolkata', 3),
    ('Project D', 4, 'delhi', 4);

select * from Project;

CREATE TABLE Works_On (
    essn CHAR(9),
    pno INT,
    hours DECIMAL(5, 2),
    PRIMARY KEY (essn, pno),
    FOREIGN KEY (essn) REFERENCES employee2(ssn),
    FOREIGN KEY (pno) REFERENCES Project(pnumber)
);

insert into Works_On (essn, pno, hours)
VALUES
    ('123', 1, 40.0),
    ('124', 2, 35.5),
    ('125', 3, 42.0),
    ('126', 4, 37.5);

select * from works_on;

CREATE TABLE Dependent (
    essn CHAR(9),
    dependent_name VARCHAR(100) primary key,
    sex CHAR(1),
    bdate DATE,
    relationship VARCHAR(50),
    FOREIGN KEY (essn) REFERENCES employee2(ssn)
);

select * from Dependent;

insert into Dependent values
    ('123', 'jansy', 'F', '2005-03-10', 'Daughter'),
    ('124', 'abi', 'M', '2010-07-15', 'Son'),
    ('125', 'sri', 'F', '2002-11-20', 'Daughter'),
    ('126', 'hyma', 'M', '2008-04-05', 'Son');


-- a)
create view employee2View (employee2ID, FirstName, LastName, Salary) as
SELECT EmployeeID, FirstName, LastName, Salary
FROM employee2;

CREATE OR REPLACE VIEW department2ManagerInfo AS
SELECT
    D.dname AS department2Name,
    CONCAT(M.fname, ' ', M.lname) AS ManagerName,
    M.salary AS ManagerSalary
FROM
    department2 D
JOIN
    employee2 M ON D.mgr_ssn = M.ssn;

select * from  department2ManagerInfo;

-- ii)
CREATE OR REPLACE VIEW ProjectSummary AS
SELECT
    P.pname AS ProjectName,
    D.dname AS Controllingdepartment2Name,
    COUNT(*) AS NumberOfemployee2s,
    SUM(W.hours) AS TotalHoursWorkedPerWeek
FROM
    Project P
JOIN
    Works_On W ON P.pnumber = W.pno
JOIN
    employee2 E ON W.essn = E.ssn
JOIN
    department2 D ON P.dnum = D.dnumber
GROUP BY
    P.pname, D.dname
HAVING
    COUNT(*) > 1;
SELECT * FROM ProjectSummary;

-- 1) iii)
CREATE OR REPLACE VIEW Updatabledepartment2 AS
SELECT
    dnumber,
    dname,
    mgr_ssn,
    mgr_start_date
FROM
    department2;
select * from Updatabledepartment2;

-- c)
INSERT INTO deparment2 (dnumber, dname, mgr_ssn, mgr_start_date)
VALUES (101, 'New_department', '129', '2023-01-15');

INSERT INTO employee2 (fname, minit, lname, ssn, bdate, address, sex, salary, super_ssn, dno)
VALUES ('rishab', 'K', 'shetty', '130', '1990-05-15', 'pune', 'M', 60000, '150', 101);