/*
 * Tarea 3 Tópicos en Data Management
 * 19-06-2023
 * Autor: Esteban Hernández
 * 
 * Se ha utilizado Dbeaver 23.1.0 como cliente para acceder a la base de datos
 * 

TABLES: titles; names; categories; directed; acted
*/

--
-- PARTE 1
--

--Respuesta 1
with main_aux(actor,id_pelicula) as 
(	
	/* Tabla con actores e ID de película */
 	select distinct "name", acted.title_id from names
	join acted on acted.name_id = names.id -- where acted.title_id=1
)
SELECT aux_1.actor AS actor1, --aux_1.id_pelicula as id_pelicula
aux_2.actor AS actor2
from main_aux as aux_1
join main_aux as aux_2
on aux_1.id_pelicula = aux_2.id_pelicula
where aux_1.actor <> aux_2.actor; -- and aux_1.id_pelicula = 1;


--Respuesta 2
with recursive co_stars(actor1, actor2) as 
(
	with main_aux(actor,id_pelicula) as 
	(
		select distinct "name", acted.title_id from names
		join acted on acted.name_id = names.id
	) 
	select aux_1.actor AS actor1, aux_2.actor AS actor2 
	from main_aux as aux_1
	join main_aux as aux_2 on aux_1.id_pelicula = aux_2.id_pelicula
	where aux_1.actor <> aux_2.actor
), 
indirect_co_star_bacon(actor) as (
	select co_stars.actor2 as actor from co_stars
	where co_stars.actor1 = 'Kevin Bacon'
    union
    select aux.actor2 as actor from indirect_co_star_bacon as ind_aux
    join co_stars as aux on ind_aux.actor = aux.actor1
)
select distinct indirect_co_star_bacon.actor from indirect_co_star_bacon; 


--Respuesta 3
with recursive co_stars(actor1, actor2) as 
(
	with main_aux(actor,id_pelicula) as 
	(
		select distinct "name", acted.title_id from names
		join acted on acted.name_id = names.id
	) 
	select aux_1.actor AS actor1, aux_2.actor AS actor2 
	from main_aux as aux_1
	join main_aux as aux_2 on aux_1.id_pelicula = aux_2.id_pelicula
	where aux_1.actor <> aux_2.actor
),indirect_co_star_carruth(actor) as (
	select co_stars.actor2 as actor from co_stars
	where co_stars.actor1 = 'Shane Carruth'
    union
    select aux.actor2 as actor from indirect_co_star_carruth as ind_aux
    join co_stars as aux on ind_aux.actor = aux.actor1
)
select distinct indirect_co_star_carruth.actor from indirect_co_star_carruth; 

--Respuesta 4
with recursive co_stars(actor1, actor2) as 
(
	with main_aux(actor,id_pelicula) as 
	(
		select distinct "name", acted.title_id from names
		join acted on acted.name_id = names.id
	) 
	select aux_1.actor AS actor1, aux_2.actor AS actor2 
	from main_aux as aux_1
	join main_aux as aux_2 on aux_1.id_pelicula = aux_2.id_pelicula
	where aux_1.actor <> aux_2.actor
), 
indirect_co_star_bacon(actor1,actor2) as (
	select co_stars.actor1 as actor1, co_stars.actor2 as actor2 from co_stars
	where co_stars.actor1 = 'Kevin Bacon'
    union
    select ind_aux.actor2 as actor1, aux.actor2 as actor2 from indirect_co_star_bacon as ind_aux
    join co_stars as aux on ind_aux.actor2 = aux.actor1
)
select distinct * from indirect_co_star_bacon; 


--
-- PARTE 2
--


--Respuesta 1

/* CON JOIN */
explain analyze 
select distinct "name" from names
join acted on names.id = acted.name_id
where acted."role" = 'Batman'
order by "name" asc;

/* SIN JOIN */
explain analyze 
select distinct "name" from names, acted
where names.id = acted.name_id  and "role" = 'Batman';


--Respuesta 2
explain analyze 
select distinct "name" from names
join acted on names.id = acted.name_id
where acted."role" = 'Batman';

--Respuesta 3
explain analyze
select * from titles
where titles.release_year = 2022;

--Respuesta 4
explain analyze
select * from titles
where titles.release_year <= 2018 and titles.release_year >= 2020;


SELECT tablename, indexname, indexdef
FROM pg_indexes
WHERE schemaname = 'public'
ORDER BY tablename, indexname;
