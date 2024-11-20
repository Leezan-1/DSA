bool checkPrimeNumber(int number)
{
    int remainder;
    for (size_t i = 2; i < number; i++)
    {
        remainder = number % i;

        if (remainder == 0)
            return false;
    }
    return true;
}

