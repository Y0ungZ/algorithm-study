function solution(genres, plays) {
  const answer = [];
  const songs = {};
  const genresAllPlays = new Map();

  genres.forEach((genre, idx) => {
    if (genresAllPlays.has(genre)) {
      genresAllPlays.set(genre, genresAllPlays.get(genre) + plays[idx]);
    } else {
      genresAllPlays.set(genre, plays[idx]);
    }
    songs[genre] = [];
  });

  plays.forEach((play, idx) => {
    songs[genres[idx]].push([idx, play]);
  });

  const mostLovedGenres = Array.from(genresAllPlays).sort((a, b) => b[1] - a[1]);

  mostLovedGenres.forEach((resultGenre) => {
    const [genre, total] = resultGenre;
    const mostLovedSongs = Array.from(songs[genre]).sort((a, b) => b[1] - a[1] || a[0] - b[0]);
    const resultSongs = mostLovedSongs.slice(0, 2);

    resultSongs.forEach((song) => {
      answer.push(song[0]);
    });
  });

  return answer;
}
