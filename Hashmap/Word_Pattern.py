
// Roman Olsen
// Leetcode top 150
// Word Pattern
//


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        if (len(pattern) != len(words)):
            return False
        seen_words = set()
        table = {}
        for i in range(len(pattern)):
            if table.get(pattern[i]) is None:  # doesnt exist
                table[pattern[i]] = words[i]
                old_len = len(seen_words)
                seen_words.add(words[i])
                if (old_len == len(seen_words)):
                    return False
            else:
                if table[pattern[i]] != words[i]:
                    return False

        return True
