// optimal page replacement algo

#include <iostream>
#include <algorithm>
#include<stdlib.h>

using namespace std;

int main()
{
    int i, j, k, total_frame, total_page, *frame, *page, *found_in_pos, *temp_arr;
    cout << "Enter total frame & total page: ";
    cin >> total_frame >> total_page;

    frame = (int *)malloc(total_frame * sizeof(int));
    found_in_pos = (int *)malloc(total_frame * sizeof(int));
    temp_arr = (int *)malloc(total_frame * sizeof(int));
    page = (int *)malloc(total_page * sizeof(int));
    

    for (i = 0; i < total_frame; i++)
    {
        frame[i] = -1;
    }

    // inputs
    // 4 20
    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

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

            // if any frame is empty then keep page there
            if (current_frame < total_frame)
            {
                frame[current_frame] = page[i];
                current_frame++;
            }

            else
            {
                // find out the position for page stored in frame from upcomming page ref
                for (j = 0; j < total_frame; j++)
                {
                    found = -1;  // no same page in upcomming ref
                    for (k = i + 1; k < total_page; k++)
                    {
                        if (frame[j] == page[k])
                        {
                            found = k;
                            break;
                        }
                    }
                    found_in_pos[j] = found;
                    temp_arr[j] = found;
                }

                sort(temp_arr, temp_arr+total_frame);

                int last_pos = temp_arr[total_frame-1];
                int temp;

                for (j = 0; j < total_frame; j++)
                {
                    if (found_in_pos[j] == -1)
                    {
                        temp = j;   // if any page is found which will not be there in ref string, then its better to replace that
                        break;
                    }
                    else if (found_in_pos[j] == last_pos)
                    {
                        temp = j;
                    }
                }
                frame[temp] = page[i];
            }
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


