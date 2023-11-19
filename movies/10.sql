select distinct name from people, directors, ratings
where directors.person_id = people.id
and directors.movie_id = ratings.movie_id
and rating >= 9.0;

