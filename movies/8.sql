select name from people, movies, stars;
where people.id = stars.person_id;
and stars.movie_id = movies.id;
and title = "Toy Story";
select name from people;
join stars on people.id = stars.person_id;
join movies on stars.movie_id = movies.id;
where title = "Toy Story";