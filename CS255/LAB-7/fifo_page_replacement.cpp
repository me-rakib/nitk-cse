#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int i, j, total_frame, total_page, *frame, *page;
    cout << "Enter total frame & total page: ";
    cin >> total_frame >> total_page;

    frame = new (nothrow) int(total_frame);
    page = new (nothrow) int(total_page);

    for (i = 0; i < total_frame; i++)
    {
        frame[i] = -1;
    }

    // inputs
    // 3 15
    // 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

    cout << "Enter reference string: ";
    for (i = 0; i < total_page; i++)
    {
        cin >> page[i];
    }

    int found, hit = 0, miss = 0, current_frame = 0;

    for (i = 0; i < total_page; i++)
    {
        found = 0;
        for (j = 0; j < total_frame; j++)
        {
            // if page is found in frame, then no page fault
            if (page[i] == frame[j])
            {
                found = 1;
                break;
            }
        }

        // no page fault, then hit
        if (found == 1)
        {
            hit++;
        }
        // page fault, then miss
        else
        {
            miss++;
            frame[current_frame] = page[i];
            current_frame = (current_frame + 1) % total_frame;
        }

        for (j = 0; j < total_frame; j++)
        {
            cout << frame[j] << " ";
        }
        cout << "\n"
             << endl;
    }

    cout << "\nTotal Hit: " << hit << endl;
    cout << "Hit Ratio: " << ((float)hit / total_page) * 100 << endl;

    cout << "Total Miss: " << miss << endl;
    cout << "Miss Ratio: " << ((float)miss / total_page) * 100 << endl;

    return 0;
}