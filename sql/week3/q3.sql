select * from employee;

#a)
select concat(ename,'-',job) as name from employee;

#b)
select ename,Sal,15*(Sal)/1000 as increase from employee;

#c)
select * from employee;
-- insert into employee values(117,'phanvi','Sales','113',10000,2320,323,10);
-- insert into employee values(118,'ranii','Sales','113',5000,2300,320,10)
select managerid,min(Sal) from employee group by managerid;

select * from employee where managerid is not null and Sal in (select min(Sal) from employee group by managerid);

#d) 
select deptno,avg(Sal) from employee group by deptno;

#e)
select count(deptno),deptno,avg(Sal) from employee group by deptno having count(deptno)>2;

#f)
select ename, AVG(Sal) as average_salary from employee
where deptno = 10
group by ename;


