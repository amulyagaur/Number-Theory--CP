for (i=1;i*i<=b;i++)                                        
        {
            sq = i*i;
            first_div_by_i = (((a-1)/i) +1) * i;

            for (j=first_div_by_i;j<=b;j+=i)              
            {
                if (j<sq)
                    continue;
                else if (j==sq)
                {
                    arr[j-a]++;
                }
                else arr[j-a] += 2;
            }
        }