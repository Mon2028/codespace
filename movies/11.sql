select title from movies, stars, people, ratings
where movies.id = stars.movie_id and movies.id = ratings.movie_id
and people.id = stars.person_id
and name = "Chadwick Boseman"
order by rating desc limit 5;
