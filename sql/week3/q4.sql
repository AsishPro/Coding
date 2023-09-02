#a)
select count(*) from employee where deptno=10;

#b)
-- insert into employee values(119,'sakura','Clerk','113',3000,100,100,1);
select min(Sal) from employee where job='Clerk';
select * from employee where Sal in (select min(Sal) from employee where job='Clerk');

#c)
select min(Sal),max(Sal),avg(Sal) from employee;

#d)
select job,min(Sal),max(Sal) from employee group by job;

#e)
select * from employee 
order by ename desc;

#f)
select * from employee 
order by empno