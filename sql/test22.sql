show databases;
use dbms;
select * from employee where empno in (select Cust_name from customer);
select * from employee;
select avg(Sal) from employee;
select * from employee where Sal>(select avg(Sal) from employee);
update employee 
set Sal=Sal-(Sal*10/100)
where Sal>140000;
select * from employee;
select * from employee where job= case when empno=101 then 'Manager' else 'clerk' end;
select * from employee where job <> "Manager";
select sum(Sal) from employee;

-- select * from employee 

-- select * from employee where job="manager" union (select * from employee where job="clerk");
-- select * from employee where job="manager" intersect (select * from employee where job="clerk");
-- select * from employee where job="manager" intersect (select * from employee where deptno=10);
-- select * from employee where job="manager" except (select * from employee where deptno=10);

select distinct T.Sal
from employee as T, employee as S
where T.Sal < S.Sal;

select T.Sal,S.Sal 
from employee as T, employee as S;

select * from employee where job not in ("manager");
select * from employee except (select * from employee where job="manager");

select job, avg (Sal) as avg_salary
from employee
group by job;

-- select * from employee where Commision_new>300

select * from employee where Sal in (select Sal from employee where Commision_new>300);

SELECT *
FROM employee
WHERE EXISTS (SELECT 0 FROM customer WHERE customer.Cust_name = employee.empno);

#subqueries in from clause
select * from (select job,Avg(Sal) as avgsal from employee group by job) as temp where avgsal>42000; #alias name
#can also be done using having clause

select * from (select Cust_city,count(Cust_city)as city from customer group by Cust_city)as temp
order by city desc limit 1;

-- with max_city(value) as 

-- select * from employee cross join customer
-- SELECT *
-- FROM employee
-- NATURAL JOIN customer;

SELECT *
FROM employee AS E
JOIN customer AS c ON E.empno = c.Cust_name;


SELECT *
FROM employee,customer
where employee.empno=customer.Cust_name;

create view emp as
select empno,ename,job,Sal
from employee;

select * from emp;

create view avg_sal as
select avg(Sal) from employee;
select * from avg_sal;
select * from employee where Sal> (select * from avg_Sal); #no need of updation of sal everytime
drop view emp;

use dbms;
delete from test;
select * from test;
