

int arthematicOperation(int first_operand, int second_operand, string operators)
{

    if (operators == "+")
        return first_operand + second_operand;

    else if (operators == "-")
        return first_operand - second_operand;

    else if (operators == "*")
        return first_operand * second_operand;

    else if (operators == "/")
    {
        if (second_operand != 0)
            return first_operand / second_operand;
        else
            cerr << "Division by zero" << endl;
    }

    else if (operators == "%")
    {
        if (second_operand != 0)
            return first_operand % second_operand;
        else
            cerr << "Division by zero" << endl;
    }

    else
        throw invalid_argument("Unknown operator");
    return 0;
}

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

