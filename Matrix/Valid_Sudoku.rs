//Roman Olsen
//Leetcode top 150
// 36 Valid Sudoku
//
// The solutions are similar in time, but solution 2 is more modular
use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut hs = HashSet::new();
        // Check all the columns
        for col in 0..9 {
            hs.clear();
            for row in 0..9 {
                let element = board[row][col];
                if element != '.' && !hs.insert(element) {
                    return false;
                }
            }
        }

        // Check the rows
        for row in 0..9 {
            hs.clear();
            for col in 0..9 {
                let element = board[row][col];
                if element != '.' && !hs.insert(element) {
                    return false;
                }
            }
        }

        // Check 3x3 grids
        for i in (0..9).step_by(3) {
            for j in (0..9).step_by(3) {
                hs.clear();
                for row in i..(i + 3) {
                    for col in j..(j + 3) {
                        let element = board[row][col];
                        if element != '.' && !hs.insert(element) {
                            return false;
                        }
                    }
                }
            }
        }

        true
    }
}
//Solution 2
//
use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row_set = HashSet::new();
        let mut col_set = HashSet::new();
        let mut sub_box_sets = vec![HashSet::new(); 9];

        for r in 0..9 {
            for c in 0..9 {
                if let Some(digit) = board[r][c].to_digit(10) {
                    if !row_set.insert((r, digit)) {
                        return false;
                    }

                    if !col_set.insert((c, digit)) {
                        return false;
                    }

                    if !sub_box_sets[3 * (r / 3) + c / 3].insert(digit) {
                        return false;
                    }
                }
            }
        }
        true
    }
}
