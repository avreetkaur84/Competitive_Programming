# 🎵 Playlist Manager

A mini project to simulate a music playlist manager using a Doubly Linked List.

---

## 📚 Problem Statement

Design and implement a playlist manager for a music application. The playlist should allow users to:

1. Move to the **next** and **previous** songs.
2. **Add** a song to the end of the playlist.
3. **Add** a song **after the current** playing song.
4. **Remove** the **current** song from the playlist.
5. Show the **current** playing song.
6. Show the **entire playlist** in forward and backward directions.

---

## 💡 Requirements

- Use a **Doubly Linked List** to maintain the playlist.
- Maintain a **pointer to the current song**.
- Handle edge cases gracefully (empty list, end of list, etc.)

---

## 🔧 Operations to Implement

### 1. `addSongToEnd(String songName)`
Adds a new song at the end of the playlist.

### 2. `addSongAfterCurrent(String songName)`
Inserts a song immediately after the current song.

### 3. `removeCurrentSong()`
Deletes the current song from the playlist. After deletion, current should point to the next song (or previous if next is null).

### 4. `moveToNextSong()`
Moves the pointer to the next song, if possible.

### 5. `moveToPreviousSong()`
Moves the pointer to the previous song, if possible.

### 6. `showCurrentSong()`
Displays the name of the current playing song.

### 7. `showPlaylistForward()`
Prints the playlist from start to end.

### 8. `showPlaylistBackward()`
Prints the playlist from end to start.

---

## 🧪 Sample Flow

```text
addSongToEnd("Shape of You")
addSongToEnd("Closer")
addSongToEnd("Perfect")

showPlaylistForward()
// Output: Shape of You -> Closer -> Perfect

moveToNextSong()
showCurrentSong()
// Output: Closer

addSongAfterCurrent("Believer")
showPlaylistForward()
// Output: Shape of You -> Closer -> Believer -> Perfect

removeCurrentSong()
showPlaylistForward()
// Output: Shape of You -> Believer -> Perfect

moveToPreviousSong()
showCurrentSong()
// Output: Shape of You
````

---

## ✅ Skills Tested

* Doubly Linked List fundamentals
* Insertion and deletion logic
* Pointer handling and edge case management
* Traversal and bidirectional navigation

---

## 🧠 Bonus Challenges (Optional)

* Shuffle mode (random song selection)
* Repeat mode
* Search for a song by name
* Move a song from one position to another

---