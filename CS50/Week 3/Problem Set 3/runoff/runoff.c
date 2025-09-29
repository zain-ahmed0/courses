#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through the candidates and check if the name voted for, matches a candidate name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Updates voter preference e.g voter = 0 (1st voter), rank = 0 (1st choice)
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop through 2D array and calculate the votes
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            /*
                Check if candidate isn't eliminated and counts one vote and breaks from the loop
                If the candidate is eliminated it will increment by one and move to the next rank
               e.g rank = 1 (2nd choice)
            */

            if (candidates[preferences[i][j]].eliminated != true)
            {
                candidates[preferences[i][j]].votes += 1;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int half = (voter_count / 2) + 1;
    
    // Loop through the candidates and check if the candidate vote count is higher than half
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= half)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialize variable
    int lowest_vote_count = 0;

    /*
        Loop through candidates to find a candidate that isn't eliminated
        and get it's vote count to compare with other candidates
    */

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated != true)
        {
            lowest_vote_count = candidates[i].votes;
            break;
        }
    }

    /*
        Loop through candidates and checks if they aren't eliminated and then checks to see if the
        current count score is higher than the current candidates score
    */

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated != true)
        {
            if (lowest_vote_count > candidates[i].votes)
            {
                lowest_vote_count = candidates[i].votes;
            }
        }
    }
    return lowest_vote_count;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Loop through candidates to find if there is a tie
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated != true)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through the candidates to find a candidate with the lowest vote count to eliminate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
