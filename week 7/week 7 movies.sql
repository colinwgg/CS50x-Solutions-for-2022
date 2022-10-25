-- 1
SELECT title
  FROM movies
 WHERE year = 2008;

-- 2
SELECT birth
  FROM people
 WHERE name = "Emma Stone";

-- 3
SELECT title
  FROM movies
 WHERE year >= 2018
 ORDER BY title;

-- 4
SELECT count(rating)
  FROM ratings
 WHERE rating = 10.0;

-- 5
SELECT title, year
  FROM movies
 WHERE title
  LIKE "Harry Potter%"
 ORDER BY year;

-- 6
SELECT avg(rating)
  FROM ratings
 WHERE movie_id IN
       (SELECT id
          FROM movies
         WHERE year = 2012);

-- 7
SELECT title, rating
  FROM movies, ratings
 WHERE year = 2010
   AND id = movie_id
 ORDER BY rating DESC, title;

-- 8
SELECT name
  FROM people
  JOIN stars
    ON id = person_id
 WHERE movie_id IN
       (SELECT id
          FROM movies
         WHERE title = "Toy Story");

-- 9
SELECT name
  FROM people, stars, movies
 WHERE movies.id = stars.movie_id
   AND people.id = stars.person_id
   AND movies.year = 2004
 ORDER BY birth;

-- 10
SELECT distinct(name)
  FROM people, directors, ratings
 WHERE people.id = directors.person_id
   AND ratings.movie_id = directors.movie_id
   AND rating >= 9.0;

-- 11
SELECT title
  FROM movies, stars, ratings, people
 WHERE movies.id = ratings.movie_id
   AND people.id = stars.person_id
   AND stars.movie_id = movies.id
   AND name = "Chadwick Boseman"
 ORDER BY rating DESC
 LIMIT 5;

-- 12
SELECT title
  FROM movies, stars, people
 WHERE movies.id = stars.movie_id
   AND people.id = stars.person_id
   AND name = "Johnny Depp"
   AND title IN
       (SELECT title
          FROM movies, stars, people
         WHERE movies.id = stars.movie_id
           AND people.id = stars.person_id
           AND name = "Helena Bonham Carter");

-- 13
SELECT distinct(name)
  FROM people, movies, stars
 WHERE people.id = stars.person_id
   AND movies.id = stars.movie_id
   AND name != "Kevin Bacon"
   AND title IN
       (SELECT title
          FROM movies, stars, people
         WHERE people.id = stars.person_id
           AND movies.id = stars.movie_id
           AND name = "Kevin Bacon"
           AND birth = 1958);