select distinct(name) from people
join stars on stars.person_id=people.id
where id in (select stars.person_id from stars where stars.movie_id
in (select stars.movie_id from stars where stars.person_id = (
select id from people where name = "Kevin Bacon" and birth = 1958)))
and name != "Kevin Bacon";