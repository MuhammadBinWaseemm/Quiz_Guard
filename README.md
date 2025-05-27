# QuizGuard System

# Algorithms and Data Structure Concepts Used

# Algorithms

# SHA-256-based Complex Hashing:

Purpose: Secures user passwords, dates of birth, and institution names by generating a custom hash.
Implementation: The complex_hash function in AccountHash.cpp uses SHA-256 with salt and pepper for added security, incorporating right rotation, padding, and a custom character set for output.
Usage: Applied during signup, sign-in, password recovery, and account updates.


# Greedy Algorithm:

Purpose: Prioritizes quiz questions based on marks (value) over time when users choose to maximize marks.
Implementation: The greedyQuizGuard function in AccountHash.cpp sorts questions by marks in descending order and selects all, ignoring time constraints.
Usage: Used in the quiz-taking process when option 1 (Prioritize Marks) is selected.


# 0/1 Knapsack (Dynamic Programming):

Purpose: Optimizes quiz question selection to maximize marks within a time limit.
Implementation: The knapsack function in AccountHash.cpp uses a dynamic programming table to select questions based on time (weight) and marks (value), with backtracking to identify selected questions.
Usage: Applied in the quiz-taking process when option 2 (Prioritize Time) is selected.


# Bubble Sort:

Purpose: Reorders quiz questions based on their assigned keys during the quiz-taking process.
Implementation: In giveQuiz, a bubble sort variant swaps adjacent question nodes (including question text, answers, and marks) to reorder them.
Usage: Ensures questions are presented in the desired order after knapsack or greedy selection.



# Data Structure Concepts

# Singly Linked List:

Purpose: Manages user accounts and quiz lists.
Structures:
Node in AccountHash.cpp: Stores user details (username, hashed password, salt, pepper, etc.) and a pointer to a quiz list.
Quiz in AccountHash.cpp: Stores quiz details (name, questions, time, marks) with a pointer to the next quiz.
AllQuiz in AccountHash.cpp: Maintains a global list of all quizzes with creator usernames.


Usage: Used for account management (insertNode, delnode, searchuser) and quiz storage (createQuiz, displayUserQuizzes).


# Doubly Linked List:

Purpose: Stores quiz questions for easy navigation (forward and backward) during quiz-taking.
Structure: Questions in AccountHash.cpp contains question text, answer, marks, and pointers (next, prev).
Usage: Managed via enqueue for question creation and navigated in giveQuiz for answering questions.


# Stack:

Purpose: Tracks the current question during quiz-taking to allow revisiting.
Structure: stack in AccountHash.cpp stores question text with a next pointer.
Usage: Implemented in push, pop, and peek to manage question display and navigation (prev, next) in giveQuiz.


# Queue:

Purpose: Organizes questions during quiz creation.
Structure: Questions in AccountHash.cpp is used as a queue during enqueue.
Usage: Questions are added to the queue in createQuiz to store them sequentially.


# Vector:

Purpose: Stores question weights (time) and values (marks) for algorithmic processing.
Structures: weights and values in Quiz for knapsack and greedy algorithms; selectedQuestions and selectedQuestionss for tracking chosen questions.
Usage: Used in giveQuiz to pass data to knapsack and greedyQuizGuard.



