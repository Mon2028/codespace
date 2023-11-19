select count(title) from movies where movies.id in (select movie_id from ratings where rating = 10);
