use dbms;
create table Suppliers(sid int primary key,sName varchar(20),address varchar(20));
describe Suppliers;
insert into Suppliers values(1,'asish','rajahmundry'),(2,'supriya','bsnl'),(3,'john','newyork');
select * from Suppliers;

create table Parts(pid int,pName varchar(20),color varchar(20));
insert into Parts values(1,'sheild','red'),(2,'tires','black'),(3,'cover','red'),(4,'seats','red');

create table Catalog(sid int,pid int,cost varchar(20),primary key (sid,pid));
describe catalog;
insert into Catalog (sid, pid, cost)
values (1, 1, '50 USD'),(1, 2, '40 USD'),(2, 3, '35 USD'),(3, 4, '60 USD'),(2, 1, '55 USD'),
	   (3, 2, '48 USD'),(1, 3, '30 USD'),(2, 4, '58 USD'),(3, 1, '52 USD');

#adding foereign key
alter table Catalog
add constraint fk_1
foreign key (sid) 
references Suppliers(sid);

alter table Catalog
add constraint fk_2
foreign key (pid) 
references Parts(pid);

-- a)
select sName
from Suppliers
where sid in (select sid from Catalog where pid in (select pid from Parts where color='red'));

-- select * from Catalog,Parts where Parts.pid=Catalog.pid and Parts.color='red';
select sName from Suppliers where sid in (select sid from Catalog,Parts where Parts.pid=Catalog.pid and Parts.color='red');

-- b)
select sid from Suppliers where sid in (select sid from Catalog,Parts where Parts.pid=Catalog.pid and Parts.color='red') and
address='Rajahmundry';

-- c)
create view codered as 
select Catalog.sid,Parts.pid,Catalog.cost from Catalog,Parts where Catalog.pid=Parts.pid and Parts.color='red';
select * from codered;
select avg(cost) from codered;

-- d)
select sid,count(pid) as cpid from Catalog group by sid;
select sid,max(cpid) as max_count from (select sid,count(pid) as cpid from Catalog group by sid) as temp group by sid;
#as all three are highest 

-- e)
select sName from Suppliers where sid in 
(select sid from Catalog group by sid having count(*) = (select count(*) as count from Parts));

-- f)
select pid from Parts where color='red';

select sid from Catalog 
where pid in (select pid from Parts where color = 'red')
group by sid
having COUNT(DISTINCT pid) = (select COUNT(*) from Parts where color = 'red');

-- g)
select p.color, 
       (SELECT COUNT(DISTINCT c.sid) 
        FROM Catalog c 
        WHERE c.pid IN (SELECT pid FROM Parts p2 WHERE p2.color = p.color)) AS supplier_count
from Parts p
group by p.color;

-- h)
select sName from Suppliers where sid =
(select sid from Catalog where pid in (SELECT pid FROM Parts WHERE color = 'red') order by cost limit 1);

-- i)
select p.color, c.sid, s.sName, s.address, c.cost
from Catalog c
inner join Parts p on c.pid = p.pid
inner join Suppliers s on c.sid = s.sid
where (p.color, c.cost) in (
    select p.color, MIN(c.cost)
    from Catalog c
    inner join Parts p on c.pid = p.pid
	group by p.color
);

-- j)
select s.sName, COUNT(c.pid) AS parts_supplied
FROM Suppliers s
left join Catalog c ON s.sid = c.sid
group by s.sName;

-- k)
select Catalog.sid, sName, address, Catalog.cost
from Catalog
inner join Suppliers s ON Catalog.sid = s.sid
where Catalog.cost = (SELECT MAX(cost) FROM Catalog);

-- l)
select Suppliers.sName
from Suppliers
join Catalog on Suppliers.sid = Catalog.sid
group by Suppliers.sid, Suppliers.sName
having COUNT(Catalog.pid)>=2; 
