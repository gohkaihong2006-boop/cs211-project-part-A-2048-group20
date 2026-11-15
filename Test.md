1. Sliding and merging in each of the four directions, including movement through gaps.
Explanation: Test rows/columns with gaps, such as 0 2 0 2 0 | Tiles slide through gaps and equal tiles merge correctly in left, right, up, and down directions | Left → 4 0 0 0 0, Right → correct right-aligned result, Up → 4 0 0 0 0, Down → 0 0 0 0 4 | PASS |.
 
3. Three equal tiles and four equal tiles: no tile merges twice in one move.
Explanation: | 2 2 2 0 0, 2 2 2 2 0, and 2 2 4 0 0 | Each tile merges only once. Example: 2 2 2 0 0 → 4 2 0 0 0 | 2 2 2 0 0 → 4 2 0 0 0; 2 2 4 0 0 → 4 4 0 0 0; newly created tile did not merge again | PASS |.
   
5. A successful slide with no merge: one new 2, one counted move, no score gain.
Explanation: | 0 0 2 0 0, move left | Tile moves to first cell, score gain = 0, move count increases by 1, and exactly one new 2 is inserted | Tile slid to first cell with gain 0. Main logic counts one successful move and inserts one new 2 when changed == true | PASS |.
   
7. An unchanged move: no inserted tile and no changed counters.
Explanation:  | 2 0 0 0 0, move left | Board unchanged; no new tile; score and move count unchanged | Board unchanged and gain = 0. Main logic does not insert a tile or update counters | PASS |.
   
9. A full board with a possible merge, and a full board with no possible moves.
Explanation:  | Full board with adjacent equal tiles; then full board with no equal neighbors | Board with possible merge is not game over. Board with no empty cells or equal neighbors is game over | Possible-merge board returned not game over. No-move board returned game over | PASS |.
   
11. Several merges in one move, correct score updates, and reaching the 2048 target.
Explanation: | Include 1024 1024 and 4 4 8 8 in movement test | Create 2048, calculate all merge scores correctly, and recognize the target | Created tile 2048; total score gained = 2072 | PASS |.
    
13. Save, change the game, and load: exact restoration of all cells and counters.
Explanation:   | Save board with score 8 and move count 3, change game state, then load | All 25 cells, score, and move count restored exactly | Board and both counters restored exactly | PASS |.
    
15. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
Explanation: | Missing file and invalid save containing tile value 3 | Load rejected and current active game remains unchanged | Missing file rejected. Invalid tile 3 rejected. Active state remained unchanged | PASS |.
    
17. Help, invalid commands, new-game confirmation, and exit behavior
Explanation: | Enter h, invalid command, n with yes/no, and e | Help and invalid input do not change state. New game requires confirmation. Exit ends program cleanly | Group should run and record the actual console results before final submission | TO VERIFY |. 

