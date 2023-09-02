-- use dbms;
-- select * from customer,employee
-- where Cust_city like '_____'

-- select distinct * from employee
-- order by sal,empno

-- select * from customer,employee
-- where (job,Sal)=('sales',1000)

-- (select * from employee where sal>100000)
-- except
-- (select * from employee where sal=150000)

-- select * from employee where sal>100000 and not sal=150000

-- select distinct S.Sal
-- from employee as T ,employee as S
-- where S.Sal<T.Sal

-- select * from sailor where rating is null

-- select avg(Sal)
-- from employee

-- select count(Sal)
-- from employee

-- select avg(Sal)
-- from employee
-- where job='Engineer'

-- select avg(distinct ID)

#number of columns
-- select count(*)
-- from employee;
-- select * from employee

-- #when subgroups
-- select job,avg(Sal) as avg_sal
-- from employee  
-- group by job

-- select job,avg(Sal) as avg_sal
-- from employee  
-- group by job
-- having avg(Sal)>100000

-- select * from employee
-- having Sal>10000