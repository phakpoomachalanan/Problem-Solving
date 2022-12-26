#include <iostream>
#include <list>

using namespace std;

typedef struct people
{
    int index;
    int perfomance;
}
pepo_t;

int main(void)
{
    int n, i;
    pepo_t* person;
    list<int> lose;
    list<pepo_t> candidate;
    list<int>::iterator litr;
    list<pepo_t>::iterator itr, nitr;

    cin >> n;

    for (i=1; i<=4*n; i++)
    {
        person = (pepo_t*)malloc(sizeof(pepo_t));
        cin >> person->perfomance;
        person->index = i;
        candidate.push_back(*person);
        //cout << i << ' ' << person << '\n';
    }
    /*for (itr=candidate.begin(); itr!=candidate.end(); itr++)
    {
        cout << itr->index << ' ' << itr->perfomance << '\n';
    }*/
    while (candidate.size()>4)
    {
        itr = candidate.begin();
        for (i=0; i<candidate.size()/2; i++)
        {
            nitr = itr;
            advance(nitr, 1);
            cout << i << ' ' << itr->index << ' ' << nitr->index << '\n';
            if (itr->perfomance > nitr->perfomance)
            {
                cout << nitr->index << '\n';
                lose.push_back(nitr->index);
                //candidate.push_back(*nitr);
                //candidate.erase(nitr);
            }
            else
            {
                cout << itr->index << '\n';
                lose.push_back(itr->index);
                //candidate.push_back(*itr);
                //candidate.erase(itr);
            }
            advance(itr, 2);
        }
        
        for (itr=candidate.begin(), litr=lose.begin(); itr!=candidate.end(); itr++)
        {
            if (itr->index == *litr)
            {
                candidate.erase(itr);
                advance(litr, 1);
            }
        }
        lose.clear();
    }
    for (itr=candidate.begin(); itr!=candidate.end(); itr++)
    {
        cout << itr->index << ' ' << itr->perfomance << '\n';
    }        

    return 0;
}