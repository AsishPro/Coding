#a)
select job,Avg(Sal) from employee group by job;

#b)
select job, avg(Sal) as avg_salary
from employee
where job not in ('Manager')
group by job;

#c)
select job,Avg(Sal)
from employee
group by job
having count(job)>1;

#d)
select * from employee where Sal>(select min(Sal) from employee where deptno=2);

#e)
select *,sign(deptno) from employee;

#f)
-- adding data column to cities table
select * from cities;
alter table cities
add column named date;
update cities
set named='1967-08-14';

#finding date difference
-- select *,curdate() from cities
select *,datediff(curdate(),named) as days_diff from cities
