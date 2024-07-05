/*
3.5 An election is contested by five candidates. The candidates are numbered 1 to 5
and the voting is done by marking the candidate number on the ballot paper. Write a
program to read the ballots and count the votes cast for each candidate using an
array variable count. In case, a number read is outside the range 1 to 5, the ballot
should be considered as a 'spoilt ballot', and the program should also count the
number of spoilt ballots.
*/

#include <iostream>
using namespace std;

void countVotes(int votes[], int size)
{
    int count[6] = {0}; // Index 0 for spoilt ballots, 1-5 for candidates

    for (int i = 0; i < size; i++)
    {
        if (votes[i] >= 1 && votes[i] <= 5)
        {
            count[votes[i]]++;
        }
        else
        {
            count[0]++;
        }
    }

    cout << "Candidate 1: " << count[1] << endl;
    cout << "Candidate 2: " << count[2] << endl;
    cout << "Candidate 3: " << count[3] << endl;
    cout << "Candidate 4: " << count[4] << endl;
    cout << "Candidate 5: " << count[5] << endl;
    cout << "Spoilt Votes: " << count[0] << endl;
}

int main()
{
    int numVotes;

    cout << "Enter the number of votes: ";
    cin >> numVotes;

    int votes[numVotes];
    cout << "Enter the votes (candidate numbers 1-5):" << endl;
    for (int i = 0; i < numVotes; i++)
    {
        cin >> votes[i];
    }

    countVotes(votes, numVotes);

    return 0;
}

/*
#include <iostream>
using namespace std;

void countVote(int n)
{
    int count1 = 0,
        count2 = 0,
        count3 = 0,
        count4 = 0,
        count5 = 0,
        count0 = 0;
    if (n == 1)
    {
        count1++;
    }
    else if (n == 2)
    {
        count2++;
    }
    else if (n == 3)
    {
        count3++;
    }
    else if (n == 4)
    {
        count4++;
    }
    else if (n == 5)
    {
        count5++;
    }
    else
    {
        count0++;
    }
    cout << "Candidates1 : " << count1 << endl
         << "Candidates2 : " << count2 << endl
         << "Candidates3 : " << count3 << endl
         << "Candidates4 : " << count4 << endl
         << "Candidates5 : " << count5 << endl
         << "spoil Vote: " << count0 << endl;
}

int main()
{
    int num;

    cout << "Candidates1 : 1" << endl
         << "Candidates2 : 2" << endl
         << "Candidates3 : 3" << endl
         << "Candidates4 : 4" << endl
         << "Candidates5 : 5" << endl;
    cout << "Enter a candidates number for voting: ";
    cin >> num;
    countVote(num);

    return 0;
}
*/