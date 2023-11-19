select title from movies
join stars on movies.id = stars.movie_id
join people on people.id = stars.person_id
where name = "Helena Bonham Carter" and title
in (select title from movies
join stars on movies.id = stars.movie_id
join people on people.id = stars.person_id
where name = "Johnny Depp");