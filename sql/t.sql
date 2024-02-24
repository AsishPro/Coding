-- show databases;
-- use endsem;
-- show tables;
-- create table temp(sno int,roll varchar(20));
-- insert into temp values(1,'AP21110011239');
-- select * from temp;
-- insert into temp(roll) values('AP21110011241');
-- create table r2(roll varchar(20),place varchar(20));
-- insert into r2 values('AP21110011239','Rajahmundry');
-- insert into r2 values('AP21110011241','Vijayawada');
-- select * from temp;


show databases;
use endsem;
show tables;
create table sales(product int,category varchar(20),sales_amt int);
insert into sales values("Laptop","Electronics",800);
insert into sales values("Tablet","Electronics",120);
insert into sales values("TV","Electronics",250);
insert into sales values("phone","Electronics",300);
insert into sales values("buds","Electronics",200);
insert into sales values("fridge","appliances",700);
insert into sales values("blender","Electronics",50);
insert into sales values("buds","Electronics",1000);
select * from sales;

select * from sales where sales_amt>100 and category="Electronics";

SELECT product, SUM(sales_amt) AS total_sales
FROM sales
WHERE category = 'Electronics'
GROUP BY product
HAVING total_sales > 100;

select * from sales;
select count(distinct product) from sales;
select * from sales where sales_amt in (select max(sales_amt) from sales);

select * from sales
group by product;
