low = 0;
    up = n-1;
    while(low<=up) 
    {
        mid = (low+up)/2;
        if(temp[mid] != reg) 
        {
            if(temp[mid] < reg)
            {
                low = mid+1;
            }
            else if (temp[mid] > reg) 
            {
                up = mid-1;
            }
        }
        else 
        {
            find = true;
            break;
        }
    }
    if(find) 
    {
        for(i=0; i<n; i++)
        {
            if(reg == student[i].reg_number) 
            {
                printf("\nRegister Number %d found:\n", student[i].reg_number);
                printf("Name: %s\n", student[i].name);
                printf("Marks: ");
                for(j=0; j<6; j++)
                {
                    printf("%f ", student[i].marks[j]);
                }
            }
        }
    }