select songs from artist_id = (select id from songs where name == "Post Malone");