select distinct name from people, movies, stars
where people.id = stars.person_id
and stars.movie_id = movies.id
and year = 2004 order by birth;
