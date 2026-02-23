# Idea: Ceasar Cypher

A Caesar cipher is a simple substitution cipher that shifts each letter in the plaintext by a fixed number (the key).
Encryption: replace each letter by the letter N positions later in the alphabet, wrapping around (e.g., shift = 3: A → D, Z → C).
Decryption: shift the letters in the opposite direction by the same key.
It usually preserves case and leaves non-letter characters unchanged.
Security: trivially breakable (only 26 possible shifts for English); useful for learning/teaching, not secure for real applications.