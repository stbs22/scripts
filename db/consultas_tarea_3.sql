/*
 * Tarea 3 Tópicos en Data Management
 * 19-06-2023
 * Autor: Esteban Hernández
 * 
 * Se ha utilizado Dbeaver 23.1.0 como cliente para base de datos
 * 
*/


--Respuesta 1
select * from titles
join categories on titles.id = title_id
where category = 'Mystery' and release_year >= 2020;


--Respuesta 2
select title, rating from titles
order by rating desc limit 10;


--Respuesta 3
select "name", death_year, category, role from names
join acted on id = name_id
join categories on acted.title_id = categories.title_id
where death_year isnull and category = 'Horror';


--Respuesta 4
select distinct "name", birth_year, death_year,role  from names
join acted on id = name_id
join titles on acted.title_id = titles.id
where acted.role = 'Batman';


--Respuesta 5
select distinct "name" from names
where names.id in 
(
	select name_id from acted
	where acted.name_id in 
		(select name_id from directed)
);

/*
--Consulta para corroborar respuesta anterior--

select names.name, titles.title from acted
join titles on acted.title_id = titles.id
join names on name_id = names.id 
where acted.name_id in (select name_id from directed);
*/


--Respuesta 6
select titles.title from titles
join acted on titles.id = acted.title_id  
join names on names.id = acted.name_id
where names."name" = 'Joaquin Phoenix';


--Respuesta 7
select category, count(title_id) as number_of_titles  from categories
group by category;


--Respuesta 8
select titles.title, count(name_id) as number_of_actors 
from (select distinct name_id, title_id from acted) as tabla
join titles on id = tabla.title_id
group by titles.title having count(tabla.name_id) >= 10
order by number_of_actors desc;


--Respuesta 9
select names."name", count(tabla.title_id) as number_of_titles 
from (select distinct name_id, title_id from acted) as tabla
join names on id = tabla.name_id 
group by names."name" order by number_of_titles desc;



--Respuesta 10
select tabla.category, tabla.max_rating, titles.title from (
	select category, max(titles.rating) as max_rating from categories
	join titles on id = categories.title_id 
	group by category
) as tabla
join titles on tabla.max_rating = titles.rating
order by category;

