use dbms;
-- select * from Catalog;
-- select * from Parts;

select count(*) from Catalog,Parts where Catalog.pid=Parts.pid;
select count(*) from Parts,Catalog where Catalog.pid=Parts.pid;

insert into Catalog values(1,4,'60 USD');

-- e)
select sName from Suppliers where sid;
(select sid from Catalog group by sid having count(*) = (select count(*) as count from Parts));

-- f)
select pid from Parts where color='red';

SELECT sid FROM Catalog 
WHERE pid IN (SELECT pid FROM Parts WHERE color = 'red')
group by sid
having COUNT(DISTINCT pid) = (SELECT COUNT(*) FROM Parts WHERE color = 'red');

-- g)
select p.color, 
       (SELECT COUNT(DISTINCT c.sid) 
        FROM Catalog c 
        WHERE c.pid IN (SELECT pid FROM Parts p2 WHERE p2.color = p.color)) AS supplier_count
from Parts p
group by p.color;

-- h)
select sName from Suppliers where sid =(select sid from Catalog where pid in (SELECT pid FROM Parts WHERE color = 'red') order by cost limit 1)

-- i)

 

