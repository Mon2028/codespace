select avg(energy) from where songs.artist_id = (select id from artists where name = "Drake")