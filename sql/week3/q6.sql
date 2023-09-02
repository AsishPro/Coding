create table vendor(id int,part_type varchar(20),vendor_type varchar(20),part_cost int,date1 date,date2 date);
insert into vendor values
(1, 'assembled', 'local', 2000, '2023-07-01', '2023-08-15'),
(2, 'sub-parts', 'local', 1500, '2022-06-15', '2023-07-15'),
(3, 'sub-parts', 'non local', 1500, '2022-05-01', '2023-06-15'),
(4, 'assembled', 'non-local', 4000, '2023-12-01', '2023-05-01');
select  * from vendor;

#a)
#delivered within 6months
select * from vendor where abs(datediff(date1,date2))>182;

#b)
select * from vendor where part_type in ('assembled','sub-parts');

#c)
select vendor_type,count(*) from vendor group by vendor_type;

#d)
select * from vendor order by id;

#e)
insert into vendor values(5, 'sub-parts', 'non-local', 5000, '2021-05-01', '2023-05-01');
select * from vendor where part_type = 'sub-parts'
and part_cost > (select max(part_cost) from vendor where part_type = 'assembled');

#f)
select * from vendor where part_type = 'assembled'
and part_cost < (select max(part_cost) from vendor where part_type = 'assembled')
order by part_cost desc
limit 1;
