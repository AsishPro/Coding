use dbms;
show tables;
select * from employee;
-- insert into employee values(113,'supirya','Manager',NULL,200000,100,20,10);
-- insert into employee values(114,'ayush','pa',101,150000,100,30,10);
-- insert into employee values(115,'rohith','ppa',101,10000,100,40,10);
-- insert into employee values(116,'gowtham','assistant',101,10000,100,40,10);

#a)
select ename,Sal
from employee
where deptno=10;

select deptno,Avg(Sal) as Avg_Sal
from employee
group by deptno;

#b)
select * from Employee where Sal=(select min(Sal) from employee);

select deptno,min(Sal) from employee group by deptno;

select * from employee where (deptno,Sal) in (
select deptno,min(Sal) from employee group by deptno
);

#c) 
#display count of employees in each dept
select deptno,count(ename) from employee group by deptno;

#d)
#ordering by deptno
select deptno, ename, Sal
from employee
order by deptno;

#e)
select * from employee
where ename like 'a%' or ename like 's%';

#f)
select ename from employee
where Sal>5000

