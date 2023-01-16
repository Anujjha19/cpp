int tour(petrolPump p[], int n)
{
    // Your code here
    int defeciet = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            defeciet += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (defeciet + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
