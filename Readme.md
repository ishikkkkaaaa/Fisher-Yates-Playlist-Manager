# SMART PLAYTLIST MANAGER

## 1)Abstract 

Music is one of the great loves of our lives. Whether it’s the loss of a loved one, the start of a new relationship, or just a bright Sunday morning or a dull working Monday afternoon, there’s always a tune to match our feelings and occasions. Music is powerful. It affects our brains, our bodies, and our social connections. And there’s no doubt that many people have relied on music to get through the pandemic. Shuffle as a feature is something we tend to use every day, may it be Spotify’s shuffle play or apple music’s shuffle playlist. Shuffling is a method employed to randomize a data set to ensure an element of chance when elements from the data set are selected at random. However, an ideal or bias-free shuffle may prove to be counter-intuitive in this case as even in randomized selections, listeners tend to have inclinations towards a certain type of song depending on their mood. What we wish to design is a predictive playlist manager which takes into account various parameters like genre, artist, play duration, and release date and selects the next song on that basis.

<b><i>Keywords—Music Shuffling, Predictive playlist manager</i></b>


## 2)Introduction 

Shuffling may be a method employed to randomize a knowledge set to make sure a component of chance when elements from the info set are selected randomly. Literature has established that computers are capable of generating a perfect shuffle; Shuffling is additionally widely utilized in music players as a separate feature allowing listeners to randomize their playlists. However, a perfect or bias-free shuffle may be counter-intuitive during this case as even in randomized selections, listeners tend to possess inclinations towards a particular sort of song depending on their mood. Via this project, we propose a predictive playlist manager which will provide automated dynamic-based shuffling consistent with the user's preferences. This shuffling takes under consideration various parameters like genre, artist, play duration, and release date and selects subsequent songs thereon a basis.
Listening to the same song repeatedly is often extremely boring and aggravating. Thus shuffling songs within the playlist is a crucial task and will tend to be of considerable weight. Ideal Shuffling may be a procedure wherein the songs are randomly ordered with no preference to a song or following any particular order of placing influenced by the history of the user, during this case songs present in the playlist may or may not be of the users liking. By consciously selecting the playlist according to the songs that are currently playing, we try to provide the user with a one-of-a-kind musical experience.
A few of the shuffling algorithms are Faro’s Shuffle, the Fisher-Yates Shuffle (Knuth shuffle) Algorithm Amongst all the shuffling algorithms, the Fisher-Yates Shuffle (Knuth shuffle) Algorithm is that the most optimal and widely used algorithm. A lot of research has been done and remains to be done in order to enhance the Fisher-Yates Shuffle Algorithm and it's been applied to varied real-world applications.
We’ll be using a doubly-linked list and Nearness Factor to predict and store the song that according to your current song fits the playlist best. The nearness factor is assigned based on a 1 or 2-point increment to the default value of 0 correspondings to each “matched tag” of the two songs. The songs with a high value of nearness factor are played first. The nearness factor is calculated to support the load generator algorithm. The time that the present song is played also influences whether those almost like this are able to be played next or not.

<b><i>keywords: Artist, Album, Genre, Release Date(whether a same decade or not)</i></b>

2)Motivation

<i>“There is always an element of poetry in science. Real science and real music requires a uniform thinking process.”</i>
-Albert Einstein 


Nowadays everyone tends to listen to music while doing their work and because of this they may make or use a playlist based on different tasks they do in their whole day or based on whatever they are feeling at the moment. Reports and research suggest that listening to the same music repeatedly can cause a person to go into depression and may push him to hate music and to give up on music itself. As we realize that change is critical in life and is beneficial also. Consequently, the change of the music being heard by an individual is similarly important. Smart Shuffling is useful when a single playlist for different genres is created by the user and the user listens to the song that gives them the vibe of what they are aiming for since it suggests on the basis of what genre the user is listening to and what genre he is trying to avoid at the moment. That’s why shuffling a music playlist based on the user's particular choice is very important to achieve the goal the user has set while listening to the playlist.


## 3)Related work
 

Nowadays, shuffling the playlist is as crucial as the chords for the song, that's why all the music players have the feature. One of the renowned music players i.e., Spotify also uses a shuffling so that the users can enjoy the same playlist again and again feeling all those vibes as they felt on the first day while listening to it. 

The shuffler works by creating a new playlist with the same name as the original and copying all of the tracks to the new playlist. Once the process is complete the original playlist is removed. They have selected this method as it allows original playlists to be recovered and is much faster than other methods.

Spotify has developed a new algorithm that distributes artists and genres more evenly. For example, if there are five songs in a playlist, the algorithm will tend to play them with a gap of about 20%. 

Unfortunately, the downside to this approach is the new playlist loses some of the information associated with the original, like contributors, descriptions, and pictures. Now, Spotify admits that the algorithm isn’t random, it's actually calculated to feel more unpredictable, not less.

The reason why people feel that the random shuffle is not as randomized as we want is that “to humans, truly random does not feel random” as stated by Mattias Petter Johansson, a Spotify developer and one of the lead developers at Spotify, Babar Zafar said, “Our brain is an excellent pattern-matching device, It will find patterns where there aren’t any.”

The basic algorithm that every music player uses for the shuffling of the playlist is Fisher-Yates Shuffling Algorithm named after Ronald Fisher and Frank Yates, who first described it, and is also known as the Knuth shuffle after Donald Knuth.

<br><hr>

<p>
- SRS Link => https://docs.google.com/document/d/1oKaJ7tWlflbh6mYBAARPpOS_VzVjKHf4/edit?usp=sharing&ouid=112284160175451431408&rtpof=true&sd=true
</p>
<p>
- PPT Link => https://docs.google.com/presentation/d/1AoE646RhSWdL2nBMgBUe3aD1Of1x8cyd9vXJ2246X6E/edit?usp=sharing
</p>
<p>
- Synopsis Link => https://docs.google.com/document/d/1Rihy_uLUu18TXPlaYRs1KVXAEV3QXpTI/edit?usp=sharing&ouid=113645728901246292546&rtpof=true&sd=true
</p>

### Reference Links
- https://uxdesign.cc/randomly-not-random-2fd53536513c
- http://wwjmrd.com/upload/music-playlist-manager-using-fisher-yates-shuffling-algorithm-and-sorting_1513599334.pdf
- https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
- https://spotifyshuffler.com/Home/About
